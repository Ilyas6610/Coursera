#pragma once

#include <sstream>
#include <iostream>
#include <string>
#include <memory>
#include "date.h"

using namespace std;

enum class Comparison{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation{
    And,
    Or
};

class Node{
public:
    virtual bool Evaluate(const Date& date, const string& event) = 0;
};

class EmptyNode : public Node{
public:
    bool Evaluate(const Date& date, const string& event) override;
};

class DateComparisonNode : public Node{
public:
    DateComparisonNode(const Comparison cmp_, const Date& date);
    bool Evaluate(const Date& date, const string& event) override;
private:
    const Comparison cmp;
    const Date d;
};

class EventComparisonNode : public Node{
public:
    EventComparisonNode(const Comparison cmp_, const string& s_);
    bool Evaluate(const Date& date, const string& event) override;
private:
    const Comparison cmp;
    const string s;
};

class LogicalOperationNode : public Node{
public:
    LogicalOperationNode(const LogicalOperation l_, const shared_ptr<Node> left_, const shared_ptr<Node> right_);
    bool Evaluate(const Date& date, const string& event) override;
private:
    const LogicalOperation l;
    const shared_ptr<Node> left, right;
};
