#include <iostream>
#include <string>

using namespace std;

const int MAX_ROOMS = 10; // Maximum number of rooms in the hotel

// Room class representing a single room in the hotel
class Room
{
    public:
        Room(int number, bool isAvailable)
        {
            this->number = number;
            this->isAvailable = isAvailable;
        }

        int getNumber()
        {
            return number;
        }

        bool getAvailability()
        {
            return isAvailable;
        }

        void setAvailability(bool availability)
        {
            isAvailable = availability;
        }

    private:
        int number; // Room number
        bool isAvailable; // Availability of the room
};

// Hotel class representing the entire hotel
class Hotel
{
    public:
        Hotel()
        {
            // Initialize all rooms to be available
            for (int i = 0; i < MAX_ROOMS; i++)
            {
                rooms[i] = new Room(i + 1, true);
            }
        }

        // Check if a room is available
        bool isRoomAvailable(int number)
        {
            if (number < 1 || number > MAX_ROOMS)
            {
                return false; // Invalid room number
            }

            return rooms[number - 1]->getAvailability();
        }

        // Book a room
        void bookRoom(int number)
        {
            if (number < 1 || number > MAX_ROOMS)
            {
                return; // Invalid room number
            }

            if (!isRoomAvailable(number))
            {
                return; // Room is not available
            }

            rooms[number - 1]->setAvailability(false);
            cout << "Room " << number << " has been booked." << endl;
        }

    private:
        Room* rooms[MAX_ROOMS]; // Array of rooms in the hotel
};

int main()
{
    Hotel hotel;

    // Book room 3
    hotel.bookRoom(3);

    // Check if room 3 is available
    if (hotel.isRoomAvailable(3))
    {
        cout << "Room 3 is available." << endl;
    }
    else
    {
        cout << "Room 3 is not available." << endl;
    }

    return 0;
}
