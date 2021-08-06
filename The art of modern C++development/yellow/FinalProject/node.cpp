#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event){ return true; };


DateComparisonNode::DateComparisonNode(const Comparison cmp_, const Date& date) :
    cmp(cmp_),
    d(date)
{};

bool DateComparisonNode::Evaluate(const Date& date, const string& event){
    if( cmp == Comparison::Equal )
        return date == d;
    else if( cmp == Comparison::NotEqual )
        return date != d;
    else if( cmp == Comparison::Greater )
        return date > d;
    else if( cmp == Comparison::GreaterOrEqual )
        return date >= d;
    else if( cmp == Comparison::Less )
        return date < d;
    else if( cmp == Comparison::LessOrEqual )
        return date <= d;
};


EventComparisonNode::EventComparisonNode(const Comparison cmp_, const string& s_) :
    cmp(cmp_),
    s(s_)
{};

bool EventComparisonNode::Evaluate(const Date& date, const string& event){
    if( cmp == Comparison::Equal )
        return event == s;
    else if( cmp == Comparison::NotEqual )
        return event != s;
    else if( cmp == Comparison::Greater )
        return event > s;
    else if( cmp == Comparison::GreaterOrEqual )
        return event >= s;
    else if( cmp == Comparison::Less )
        return event < s;
    else if( cmp == Comparison::LessOrEqual )
        return event <= s;
};

LogicalOperationNode::LogicalOperationNode(const LogicalOperation l_, const shared_ptr<Node> left_, const shared_ptr<Node> right_) :
    l(l_),
    left(left_),
    right(right_)
{};

bool LogicalOperationNode::Evaluate(const Date& date, const string& event){
    if( l == LogicalOperation::And )
        return (left->Evaluate(date, event) && right->Evaluate(date, event));
    else
        return (left->Evaluate(date, event) || right->Evaluate(date, event));
};
