//
// Created by Nick on 30/09/2025.
//

// https://www.codewars.com/kata/58905bfa1decb981da00009e/train/cpp

#include <queue>
#include <vector>

using std::vector;
using std::queue;
using uint = std::size_t;

class Lift {
  public: //data
    const uint capacity;
    const uint building_height;

  private: //data
    vector<queue<int>> floor_queues;
    vector<int> passengers{};
    uint current_floor = 0;
    bool facing_upwards = true;

  public: //ctr
    Lift() = delete;
    Lift(uint capacity_in, const vector<vector<int>>& queues_in);

  public: //functions
    bool isFull() const;
    bool isEmpty() const;
    bool isFacingUpwards() const;
    int getCurrentFloor() const;
    const vector<queue<int>>& getFloorQueues() const;

    void unload();
    void load();
    void moveTo(int target_floor);
};

Lift::Lift(const uint capacity_in, const vector<vector<int>>& queues_in):
  capacity{capacity_in},
  building_height(queues_in.size()) {
  for (const auto& floor: queues_in) {
    queue<int> floor_queue{};
    for (int i: floor) floor_queue.push(i);
    floor_queues.push_back(floor_queue);
  }
}

bool Lift::isFull() const {
  //TODO: implement this method
}

bool Lift::isEmpty() const {
  //TODO: implement this method
}

bool Lift::isFacingUpwards() const {
  //TODO: implement this method
}

int Lift::getCurrentFloor() const {
  //TODO: implement this method
}

const vector<queue<int>>& Lift::getFloorQueues() const {
  //TODO: implement this method
}

void Lift::unload() {
  //TODO: implement this method
}

void Lift::load() {
  //TODO: implement this method
}

void Lift::moveTo(int target_floor) {
  //TODO: implement this method
}

vector<int> the_lift(const vector<vector<int>> &queues, const int capacity) {
  //TODO: implement this method
}
