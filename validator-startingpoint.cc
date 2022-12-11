void validate(Hotel& hotel) {
    if (hotel.rooms < 0 || hotel.availableRooms < 0 || hotel.availableRooms > hotel.rooms) {
        cout << "Invalid hotel data" << endl;
        return;
    }

    int bookedRoomsCount = 0;
    for (auto& [roomNumber, name] : hotel.bookedRooms) {
        if (roomNumber < 0 || roomNumber > hotel.rooms) {
            cout << "Invalid room number" << endl;
            return;
        }
        bookedRoomsCount++;
    }

    if (bookedRoomsCount != hotel.rooms - hotel.availableRooms) {
        cout << "Invalid booked rooms data" << endl;
        return;
    }

    cout << "Hotel data is valid" << endl;
