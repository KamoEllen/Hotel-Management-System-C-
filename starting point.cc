#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Hotel {
    int rooms;
    int availableRooms;
    map<int, string> bookedRooms;
};

int main() {
    Hotel hotel;
    hotel.rooms = 100;
    hotel.availableRooms = hotel.rooms;

    while (true) {
        cout << "Hotel Management System" << endl;
        cout << "1. Check availability" << endl;
        cout << "2. Book a room" << endl;
        cout << "3. Check booking" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "There are " << hotel.availableRooms << " rooms available in the hotel" << endl;
        } else if (choice == 2) {
            if (hotel.availableRooms > 0) {
                int roomNumber;
                cout << "Enter room number: ";
                cin >> roomNumber;

                string name;
                cout << "Enter your name: ";
                cin >> name;

                hotel.bookedRooms[roomNumber] = name;
                hotel.availableRooms--;

                cout << "Room booked successfully" << endl;
            } else {
                cout << "Sorry, all rooms are booked" << endl;
            }
        } else if (choice == 3) {
            int roomNumber;
            cout << "Enter room number: ";
            cin >> roomNumber;

            if (hotel.bookedRooms.find(roomNumber) != hotel.bookedRooms.end()) {
                cout << "Room is booked by " << hotel.bookedRooms[roomNumber] << endl;
            } else {
                cout << "Room is not booked" << endl;
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
