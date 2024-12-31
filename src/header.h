#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//bir dairenin temel bilgilerini tutar.
struct Apartment {
    string address;
    string phone;
    double price;
    double distance;
    int rooms;
    string exhibition;
};

// Dosyadan daire bilgilerini okuyarak diziye ekler.
void createApartments(Apartment apartments[], int &size, const string &filename);

// Mevcut dairelerin bilgilerini ekrana yazdırır.
void displayApartments(Apartment apartments[], int size);

// Belirtilen fiyat, uzaklık ve oda sayısı kriterlerine göre daire arar.
void searchApartments(Apartment apartments[], int size, double maxPrice, double maxDistance, int rooms);

// Belirli bir oda sayısına sahip daireleri sıralayıp gösterir.
void sortAndDisplayByRooms(Apartment apartments[], int size, int roomCount);

// Telefon numarasına göre bir dairenin bilgilerini günceller.
void updateApartmentInfo(Apartment apartments[], int size, const string &phone);

// Tüm daireleri listeden kaldırır.
void removeAllApartments(Apartment apartments[], int &size); // Tüm daireleri kaldıran yeni fonksiyon

#endif

