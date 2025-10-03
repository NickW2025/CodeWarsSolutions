//
// Created by Nick on 30/09/2025.
//

// https://www.codewars.com/kata/58905bfa1decb981da00009e/train/cpp

#include <iostream>
#include <ostream>
#include <set>
#include <vector>

using std::vector;
using std::multiset;

class Lift {
  public: //data
    const int lift_capacity;

  private: //data
    vector<vector<int>> floors;
    multiset<int> passengers{};
    int current_floor = 0;
    bool facing_upwards = true;
    vector<int> log = {0};
    vector<char> up_pressed;
    vector<char> down_pressed;

  public: //ctr
    Lift() = delete;
    Lift(int capacity_in, const vector<vector<int>>& queues_in);

  public: //functions
    bool isFull() const;
    bool isEmpty() const;
    bool isFacingUpwards() const;
    int getCurrentFloor() const;
    const vector<vector<int>>& getFloors() const;
    const vector<int>& getLog() const;

    int findNextFloor() const;
    int findNextFloorUp() const;
    int findNextFloorDown() const;

    void updateButtons();
    void reverse();
    void unload();
    void load();
    void moveTo(int target_floor);
};

Lift::Lift(const int capacity_in, const vector<vector<int>>& queues_in):
  lift_capacity{capacity_in},
  floors{queues_in},
  up_pressed{ vector<char>(floors.size())},
  down_pressed{ vector<char>(floors.size())}
  {
  for (int i = 0; i < floors.size(); ++i) {
    up_pressed[i] = 0;
    down_pressed[i] = 0;
    for (int p: floors[i]) {
      if (p > i) up_pressed[i] = 1;
      else if (p < i) down_pressed[i] = 1;
    }
  }
}

bool Lift::isFull() const {
  return (passengers.size() == lift_capacity);
}

bool Lift::isEmpty() const {
  return passengers.empty();
}

bool Lift::isFacingUpwards() const {
  return facing_upwards;
}

int Lift::getCurrentFloor() const {
  return current_floor;
}

const vector<vector<int>>& Lift::getFloors() const {
  return floors;
}

const vector<int>& Lift::getLog() const {
  return log;
}

void Lift::updateButtons() {
  up_pressed[current_floor] = 0;
  down_pressed[current_floor] = 0;
  for (const int passenger: floors[current_floor]) {
    if (passenger > current_floor) up_pressed[current_floor] = 1;
    else if (passenger < current_floor) down_pressed[current_floor] = 1;
  }
  return;
}

void Lift::reverse() {
  facing_upwards = !facing_upwards;
}

int Lift::findNextFloor() const {
  if (facing_upwards) return findNextFloorUp();
  else return findNextFloorDown();
}

int Lift::findNextFloorUp() const {
  for (int i = current_floor + 1; i < floors.size(); ++i) {
    for (int p: passengers) {
      if (p == i) return i;
    }
    if (up_pressed[i] == 1) return i;
  }
  for (std::size_t i = floors.size()-1; i > current_floor; --i) {
    if (down_pressed[i] == 1) return static_cast<int>(i);
  }
  return -1;
}

int Lift::findNextFloorDown() const {
  for (int i = current_floor-1; i >= 0; --i) {
    for (int p: passengers) {
      if (p == i) return i;
    }
    if (down_pressed[i] == 1) return i;
  }
  for (int i = 0; i < current_floor; ++i) {
    if (up_pressed[i] == 1) return i;
  }
  return -1;
}

void Lift::unload() {
  begin_unload:
  bool unloaded = false;
  for (int passenger: passengers) {
    if (passenger == current_floor) {
      passengers.erase(passengers.find(passenger));
      unloaded = true;
      break;
    }
  }
  if (unloaded) goto begin_unload;
  return;
}

void Lift::load() {
  begin_load:
  if (isFull()) return;
  bool loaded = false;
  for (int i = 0; i < floors[current_floor].size(); ++i) {
    if ((facing_upwards && floors[current_floor][i] > current_floor)
    || (!facing_upwards && floors[current_floor][i] < current_floor)) {
      passengers.insert(floors[current_floor][i]);
      floors[current_floor].erase(floors[current_floor].begin() + i);
      loaded = true;
      break;
    }
  }
  if (loaded) goto begin_load;
  return;
}

void Lift::moveTo(int target_floor) {
  if (target_floor == current_floor) return;
  facing_upwards = (target_floor > current_floor);
  log.push_back(target_floor);
  current_floor = target_floor;
  return;
}



vector<int> the_lift(const vector<vector<int>> &queues, const int capacity) {
  Lift lift(capacity, queues);
  lift.load();
  lift.updateButtons();

  while (true) {
    // find the next floor to move to.
    int next_target = lift.findNextFloor();

    // if we didn't find a valid target in the current direction,
    // reverse direction and try again.
    if (next_target == -1) {
      lift.reverse();
      lift.load();
      lift.updateButtons();
      next_target = lift.findNextFloor();
    }

    // if we still didn't find a target then we are done.
    if (next_target == -1) break;

    // move to the target floor and load/unload passengers.
    lift.moveTo(next_target);
    lift.unload();
    lift.load();
    lift.updateButtons();
  }

  if (lift.getCurrentFloor() != 0) lift.moveTo(0);
  return lift.getLog();
}


void printvec(vector<int> vec) {
  std::cout << '(';
  for (int i = 0; i < vec.size() - 1; ++i) {
    std::cout << vec[i] << ", ";
  }
  std::cout << vec[vec.size() - 1] << ")\n";
  return;
}

void liftTest() {
  vector<vector<int>> testvec = {
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {},
    {},
    {},
    {},
    {},
    {}
  };

  vector<int> result = the_lift(testvec, 4);
  printvec(result);
  return;
}