#include <iostream>
#include <string>
#include <map>

using namespace std;

// Room class to store information about a room
class Room {
public:
  string name; // name of the room
  int price;   // price of the room per night
  int beds;    // number of beds in the room
  bool booked; // whether the room is booked or not

  // constructor to initialize the room with given values
  Room(string n, int p, int b, bool bo) : name(n), price(p), beds(b), booked(bo) {}
};

// Hotel class to store information about a hotel
class Hotel {
public:
  string name;            // name of the hotel
  map<string, Room> rooms; // map to store rooms in the hotel

  // constructor to initialize the hotel with given values
  Hotel(string n) : name(n) {}

  // function to add a new room to the hotel
  void addRoom(string roomName, int price, int beds) {
    rooms[roomName] = Room(roomName, price, beds, false);
  }

  // function to book a room in the hotel
  void bookRoom(string roomName) {
    rooms[roomName].booked = true;
  }

  // function to check availability of rooms in the hotel
  void checkAvailability() {
    cout << "Rooms available in hotel " << name << ":" << endl;
    for (auto &room : rooms) {
      if (!room.second.booked) {
        cout << room.first << " (" << room.second.beds << " beds, $" << room.second.price << " per night)" << endl;
      }
    }
  }
};

int main() {
  Hotel h("Hilton"); // create a hotel object

  // add rooms to the hotel
  h.addRoom("Standard", 100, 1);
  h.addRoom("Deluxe", 200, 2);
  h.addRoom("Suite", 300, 3);

  // check availability of rooms in the hotel
  h.checkAvailability();

  // book a room in the hotel
  h.bookRoom("Standard");

  // check availability of rooms in the hotel again
  h.checkAvailability();

  return 0;
}
