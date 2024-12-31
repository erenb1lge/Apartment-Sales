#include "header.h"

// Yeni daireleri oluşturur ve dosyaya kaydeder.
void createApartments(Apartment apartments[], int &size, const string &filename) {
    ofstream outFile(filename, ios::app); // Dosyayı ekleme modunda açar.
    char addMore = 'y'; // Kullanıcının daha fazla daire eklemek isteyip istemediğini kontrol eder.
    
    while (addMore == 'y' || addMore == 'Y') {
        // Kullanıcıdan daire bilgilerini alır.
        cout << "Enter the details for apartment " << size + 1 << ":\n";
        cout << "Address: "; cin >> apartments[size].address;
        cout << "Phone: "; cin >> apartments[size].phone;

        // Fiyat girişini doğrular.
        while (true) {
            cout << "Price ($): ";
            if (cin >> apartments[size].price) break;
            else {
                cout << "Invalid input. Please enter a valid price.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        // Mesafeyi doğrular.
        while (true) {
            cout << "Distance to center (km): ";
            if (cin >> apartments[size].distance) break;
            else {
                cout << "Invalid input. Please enter a valid distance.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        // Oda sayısını doğrular.
        while (true) {
            cout << "Number of rooms: ";
            if (cin >> apartments[size].rooms) break;
            else {
                cout << "Invalid input. Please enter a valid number of rooms.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cout << "Exhibition (e.g., North, South): "; cin >> apartments[size].exhibition;

        // Bilgileri dosyaya kaydeder.
        outFile << apartments[size].address << " "
                << apartments[size].phone << " "
                << apartments[size].price << " "
                << apartments[size].distance << " "
                << apartments[size].rooms << " "
                << apartments[size].exhibition << "\n";

        size++; // Daire sayısını artırır.

        cout << "Do you want to add another apartment? (y/n): ";
        cin >> addMore;
    }
    outFile.close(); // Dosyayı kapatır.
}

// Tüm daireleri ekrana yazdırır.
void displayApartments(Apartment apartments[], int size) {
    if (size == 0) {
        cout << "No apartments available.\n"; // Daire yoksa uyarı gösterir.
        return;
    }

    // Daire bilgilerini sırayla ekrana yazdırır.
    for (int i = 0; i < size; i++) {
        cout << "Apartment " << i + 1 << ":\n";
        cout << "Address: " << apartments[i].address << "\n";
        cout << "Phone: " << apartments[i].phone << "\n";
        cout << "Price: " << apartments[i].price << "\n";
        cout << "Distance to center: " << apartments[i].distance << " km\n";
        cout << "Rooms: " << apartments[i].rooms << "\n";
        cout << "Exhibition: " << apartments[i].exhibition << "\n";
        cout << "-------------------------\n";
    }
}

// Belirli kriterlere göre daire arar.
void searchApartments(Apartment apartments[], int size, double maxPrice, double maxDistance, int rooms) {
    if (size == 0) {
        cout << "No apartments available to search.\n";
        return;
    }

    bool found = false; // Eşleşen daire bulunup bulunmadığını kontrol eder.
    for (int i = 0; i < size; i++) {
        if (apartments[i].price <= maxPrice && apartments[i].distance <= maxDistance && apartments[i].rooms == rooms) {
            found = true;
            cout << "Apartment " << i + 1 << ":\n";
            cout << "Address: " << apartments[i].address << "\n";
            cout << "Phone: " << apartments[i].phone << "\n";
            cout << "Price: " << apartments[i].price << "\n";
            cout << "Distance to center: " << apartments[i].distance << " km\n";
            cout << "Rooms: " << apartments[i].rooms << "\n";
            cout << "Exhibition: " << apartments[i].exhibition << "\n";
            cout << "-------------------------\n";
        }
    }
    if (!found) {
        cout << "No apartments found matching the criteria.\n";
    }
}

// Belirli oda sayısına göre daireleri fiyatlarına göre sıralar ve gösterir.
void sortAndDisplayByRooms(Apartment apartments[], int size, int roomCount) {
    if (size == 0) {
        cout << "No apartments available to sort.\n";
        return;
    }

    // Fiyata göre sıralama yapılır.
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (apartments[i].rooms == roomCount && apartments[j].rooms == roomCount) {
                if (apartments[i].price > apartments[j].price) {
                    swap(apartments[i], apartments[j]);
                }
            }
        }
    }
    
    // Sıralanmış daireleri ekrana yazdırır.
    cout << "Apartments with " << roomCount << " rooms, sorted by price:\n";
    for (int i = 0; i < size; i++) {
        if (apartments[i].rooms == roomCount) {
            cout << "Apartment " << i + 1 << ":\n";
            cout << "Address: " << apartments[i].address << "\n";
            cout << "Phone: " << apartments[i].phone << "\n";
            cout << "Price: " << apartments[i].price << "\n";
            cout << "Distance to center: " << apartments[i].distance << " km\n";
            cout << "Rooms: " << apartments[i].rooms << "\n";
            cout << "Exhibition: " << apartments[i].exhibition << "\n";
            cout << "-------------------------\n";
        }
    }
}

// Telefon numarasına göre bir dairenin bilgilerini günceller.
void updateApartmentInfo(Apartment apartments[], int size, const string &phone) {
    if (size == 0) {
        cout << "No apartments available to update.\n";
        return;
    }

    bool updated = false;
    for (int i = 0; i < size; i++) {
        if (apartments[i].phone == phone) {
            cout << "Updating apartment with phone number: " << phone << "\n";
            cout << "Enter new phone number: "; cin >> apartments[i].phone;
            cout << "Enter new price: "; cin >> apartments[i].price;
            updated = true;
            break;
        }
    }
    if (!updated) {
        cout << "No apartment found with the given phone number.\n";
    }
}

// Tüm daireleri kaldırır.
void removeAllApartments(Apartment apartments[], int &size) {
    size = 0; // Daire sayısını sıfırlar.
    cout << "All apartments have been removed.\n";
}

