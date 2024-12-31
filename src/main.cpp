#include "header.h"

int main() {
    const int maxSize = 100; // Dizinin maksimum boyutu
    Apartment apartments[maxSize]; // Daire bilgilerini tutan dizi
    int size = 0;  // Mevcut daire sayısını takip eder
    
    int choice; // Kullanıcı seçimleri için değişken
    string filename = "apartments.txt"; // Daire bilgilerini içeren dosya adı
    
    do {
        // Ana menü seçeneklerini ekrana yazdırır
        cout << "Apartment Sales Menu\n";
        cout << "1. Create apartment\n"; // Yeni daire oluştur
        cout << "2. Display all apartment records\n"; // Tüm daireleri görüntüle
        cout << "3. Search for apartments by price, distance, and rooms\n"; // Belirli kriterlere göre arama
        cout << "4. Display apartments sorted by price with a specific number of rooms\n"; // Belirli oda sayısına göre sıralı göster
        cout << "5. Update apartment information by phone number\n"; // Telefon numarasına göre güncelle
        cout << "6. Remove all apartments\n"; // Tüm daireleri sil
        cout << "7. Exit\n"; // Programdan çıkış yap
        cout << "Enter your choice: "; // Kullanıcıdan seçim al
        cin >> choice;
        
        switch (choice) {
            case 1:
                // Daire bilgilerini oluştur ve dosyadan yükle
                createApartments(apartments, size, filename);
                break;
            case 2:
                // Hiç daire yoksa uyarı mesajı göster
                if (size == 0) {
                    cout << "No apartments added yet.\n";
                } else {
                    // Mevcut daireleri ekrana yazdır
                    displayApartments(apartments, size);
                }
                break;
            case 3: {
                // Hiç daire yoksa uyarı mesajı göster
                if (size == 0) {
                    cout << "No apartments added yet.\n";
                } else {
                    // Belirli kriterlere göre arama yap
                    double maxPrice, maxDistance;
                    int rooms;
                    cout << "Enter maximum price: "; cin >> maxPrice;
                    cout << "Enter maximum distance to center (km): "; cin >> maxDistance;
                    cout << "Enter number of rooms: "; cin >> rooms;
                    searchApartments(apartments, size, maxPrice, maxDistance, rooms);
                }
                break;
            }
            case 4: {
                // Hiç daire yoksa uyarı mesajı göster
                if (size == 0) {
                    cout << "No apartments added yet.\n";
                } else {
                    // Belirli oda sayısına göre daireleri sıralı göster
                    int roomCount;
                    cout << "Enter the number of rooms: "; cin >> roomCount;
                    sortAndDisplayByRooms(apartments, size, roomCount);
                }
                break;
            }
            case 5: {
                // Hiç daire yoksa uyarı mesajı göster
                if (size == 0) {
                    cout << "No apartments added yet.\n";
                } else {
                    // Telefon numarasına göre daire bilgilerini güncelle
                    string phone;
                    cout << "Enter phone number of apartment to update: ";
                    cin >> phone;
                    updateApartmentInfo(apartments, size, phone);
                }
                break;
            }
            case 6:
                // Tüm daireleri kaldır
                removeAllApartments(apartments, size);
                break;
            case 7:
                // Programdan çıkış mesajı
                cout << "Exiting the program.\n";
                break;
            default:
                // Geçersiz seçim uyarısı
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7); // Kullanıcı 7 seçeneğini seçene kadar döngüyü devam ettir
    
    return 0; // Program başarıyla sonlandı
}

