// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


class Window {
private:
	float width, height;
public:
	void setWindowParams() {
		std::cout << "Window's width: ";
		std::cin >> width;
		std::cout << "Window's height: ";
		std::cin >> height;
	}

	float windowsGlassArea() {
		return width * height;
	}

	~Window(){
		std::cout << "Window is deleted" << endl;
	}
};

class Parquet {
private:
	float length, width;
public:
	void setParquetParams() {
		std::cout << "Parquet's width: ";
		std::cin >> width;
		std::cout << "Parquet's length: ";
		std::cin >> length;
	}

	float getParquetArea(){
		return width * length;
	}

	~Parquet() {
		std::cout << "Parquet is deleted" << endl;
	}
};

class Room {
private:
	float length, height, width, numberLM;
	int numberWindows;
	string roomColor;
	Window window;
	Parquet parquet;
public:
	void setRoomParams() {
		std::cout << "Room's width: ";
		std::cin >> width;
		std::cout << "Room's length: ";
		std::cin >> length;
		std::cout << "Room's height: ";
		std::cin >> height;
		std::cout << "Room's number L per M^2: ";
		std::cin >> numberLM;
		std::cout << "Room's number of windows: ";
		std::cin >> numberWindows;
		std::cout << "Room's color: ";
		std::cin >> roomColor;
		std::cout << endl;
		window.setWindowParams();
		std::cout << endl;
		parquet.setParquetParams();
	}

	float getRoomsV() {
		return width * length * height;
	}

	float getFloorArea() {
		return width * length;
	}

	float getGlassArea() {
		return numberWindows * window.windowsGlassArea();
	}

	int getNumberParquet() {
		return ceil(getFloorArea() / parquet.getParquetArea());
	}

	float getWallArea() {
		return height * 2 * (width + length);
	}

	float getNumberLPaint() {
		return numberLM * (getWallArea() - getGlassArea());
	}

	void roomCharacteristics() {
		std::cout << endl << "Room's characteristics: " << endl;
		std::cout << "Room's V: " << getRoomsV() << endl;
		std::cout << "Glass for windows for this rooom: " << getGlassArea() << endl;
		std::cout << "Number of Parquet: " << getNumberParquet() << endl;
		std::cout << "Paint: " << getNumberLPaint() << endl;
	}

	~Room() {

		std::cout << "Room is deleted" << endl;

	}
};


class Flat {
private:
	int numberRooms;
	Room* rooms;
	float flatV = 0, glassArea = 0, numberLPaint = 0;
	int numberParquet = 0;
public:
	void setFlatParams() {
		std::cout << "Number of rooms: ";
		std::cin >> numberRooms;
		rooms = new Room[numberRooms];
		for (int i = 0; i < numberRooms; i++) {
			std::cout << "Room " << i + 1 << endl;
			rooms[i].setRoomParams();
			rooms[i].roomCharacteristics();
		}
		
	}

	float getFlatV() {
		for (int i = 0; i < numberRooms; i++) {
			flatV = flatV + rooms[i].getRoomsV();
		}
		return flatV;
	}

	float getGlassArea() {
		for (int i = 0; i < numberRooms; i++) {
			glassArea += rooms[i].getGlassArea();
		}
		return glassArea;
	}

	float getNumberLPaint() {
		for (int i = 0; i < numberRooms; i++) {
			numberLPaint += rooms[i].getNumberLPaint();
		}
		return numberLPaint;
	}

	int getNumberParquet() {
		for (int i = 0; i < numberRooms; i++) {
			numberParquet += rooms[i].getNumberParquet();
		}
		return numberParquet;
	}

	void flatCharacteristics() {
		std::cout << endl << "Flat's characteristics: " << endl;
		std::cout << "Flat's V: " << getFlatV() << endl;
		std::cout << "Glass for windows for this flat: " << getGlassArea() << endl;
		std::cout << "Number of Parquet: " << getNumberParquet() << endl;
		std::cout << "Paint: " << getNumberLPaint() << endl;
	}

	
	~Flat() {
		delete[] rooms;
	}
};

class House {
private:
	int numberFloor, numberFlats, numberParquet = 0;
	float houseV = 0, glassArea = 0, numberLPaint = 0;
	Flat* flats;
public:
	void setHouseParams() {
		std::cout << "Number of floors: ";
		std::cin >> numberFloor;
		std::cout << "Number of flats: ";
		std::cin >> numberFlats;
		flats = new Flat[numberFloor * numberFlats];
		for (int i = 0; i < numberFloor * numberFlats; i++) {
			std::cout << "Flat " << i + 1 << endl;
			flats[i].setFlatParams();
			flats[i].flatCharacteristics();
		}
	}

	float getHouseV() {
		for (int i = 0; i < numberFloor * numberFlats; i++) {
			houseV += flats[i].getFlatV();
		}
		return houseV;
	}

	float getGlassArea() {
		for (int i = 0; i < numberFloor * numberFlats; i++) {
			glassArea = flats[i].getGlassArea();
		}
		return glassArea;
	}

	float getNumberLPaint() {
		for (int i = 0; i < numberFloor * numberFlats; i++) {
			numberLPaint += flats[i].getNumberLPaint();
		}
		return numberLPaint;
	}

	int getNumberParquet() {
		for (int i = 0; i < numberFloor * numberFlats; i++) {
			numberParquet += flats[i].getNumberParquet();
		}
		return numberParquet;
	}

	void houseCharacteristics() {
		std::cout << endl << "House's characteristics: " << endl;
		std::cout << "Number of floors: " << numberFloor << endl;
		std::cout << "Number of flats: " << numberFlats << endl;
		std::cout << "House's V: " << getHouseV() << endl;
		std::cout << "Glass for windows for this flat: " << getGlassArea() << endl;
		std::cout << "Number of Parquet: " << getNumberParquet() << endl;
		std::cout << "Paint: " << getNumberLPaint() << endl;
	}

	~House() {
		delete[] flats;
	}
};

class Street {
private:
	int numberHouses, numberParquet;
	float glassArea = 0, numberLPaint = 0;
	House* houses;
public:
	void setStreetParams() {
		std::cout << "Number of houses: ";
		std::cin >> numberHouses;
		houses = new House[numberHouses];
		for (int i = 0; i < numberHouses; i++) {
			std::cout << "House " << i + 1 << endl;
			houses[i].setHouseParams();
			houses[i].houseCharacteristics();
		}
	}

	
	float getGlassArea() {
		for (int i = 0; i < numberHouses; i++) {
			glassArea += houses[i].getGlassArea();
		}
		return glassArea;
	}

	float getNumberLPaint() {
		for (int i = 0; i < numberHouses; i++) {
			numberLPaint += houses[i].getNumberLPaint();
		}
		return numberLPaint;
	}

	int getNumberParquet() {
		for (int i = 0; i < numberHouses; i++) {
			numberParquet += houses[i].getNumberParquet();
		}
		return numberParquet;
	}

	void streetCharacteristics() {
		std::cout << endl << "Street's characteristics: " << endl;
		std::cout << "Number of houses: " << numberHouses << endl;
		std::cout << "Glass for windows for this street: " << getGlassArea() << endl;
		std::cout << "Number of Parquet: " << getNumberParquet() << endl;
		std::cout << "Paint: " << getNumberLPaint() << endl;
	}

	~Street() {
		delete[] houses;
	}
};
int main()
{
	Street street;
	street.setStreetParams();
	street.streetCharacteristics();

	system("pause");
	return 0;
}

