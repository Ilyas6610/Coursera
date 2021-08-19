#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>

using namespace std;

class ReadingManager {
public:
  ReadingManager(): pages(1001, 0){};

  void Read(int user_id, int page_count) {
      AddUser(page_count, user_id);
    }

  double Cheer(int user_id) const {
    if (user_to_pages.find(user_id) == user_to_pages.end() || user_to_pages.at(user_id) == 0) {
      return 0;
    }
    const int user_count = user_to_pages.size();
    if (user_count == 1) {
      return 1;
    }
    const int page_count = user_to_pages.at(user_id);
    int position = pages[page_count];
    /*for( const auto& it : pages_to_user ){
        if(it.first >= page_count )
            break;
        position+=it.second;
    }
    if (position == 0) {
        return 0;
    }*/
    // По умолчанию деление целочисленное, поэтому
    // нужно привести числитель к типу double.
    // Простой способ сделать это — умножить его на 1.0.
    return (position) * 1.0 / (user_count - 1);
  }

private:
  // Статическое поле не принадлежит какому-то конкретному
  // объекту класса. По сути это глобальная переменная,
  // в данном случае константная.
  // Будь она публичной, к ней можно было бы обратиться снаружи
  // следующим образом: ReadingManager::MAX_USER_COUNT.
  static const int MAX_USER_COUNT_ = 100'000;

  unordered_map<int, int> user_to_pages;
  vector<int> pages;

  void AddUser(int page_count, int user_id) {
    if( user_to_pages.find(user_id) == user_to_pages.end() )
        for( auto it = pages.begin() + page_count + 1; it != pages.end(); it++){
            *it += 1;
        }
    else
        for( auto it = pages.begin() + user_to_pages[user_id] + 1; it != pages.end() && it != (pages.begin() + page_count + 1); it++ )
            (*it)--;
    //cout << "KEK " << pages[page_count] << endl;

    user_to_pages[user_id] = page_count;
  }
};


int main() {
  // Для ускорения чтения данных отключается синхронизация
  // cin и cout с stdio,
  // а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}
