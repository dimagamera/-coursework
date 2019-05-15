#include <string>
#include <iostream>
using namespace std;

class header {
public:
	// set text
	void SefNum(string Num) {
		this->Num = Num;
	}
	void SefType(string Type) {
		this->Type = Type;
	}
	void SefProduct(string Product) {
		this->Product = Product;
	}
	void SefCharacteristic(string Characteristic) {
		this->Characteristic = Characteristic;
	}
	void SefGoods(string Goods) {
		this->Goods = Goods;
	}
	void SefCount(string Count) {
		this->Count = Count;
	}
	void SefRAM(string RAM) {
		this->RAM = RAM;
	}
	void SefVideocard(string Videocard) {
		this->Videocard = Videocard;
	}
	void SefCPU(string CPU) {
		this->CPU = CPU;
	}
	void SefCAM(string CAM) {
		this->CAM = CAM;
	}
	// GET text
		string GefNum() {
		return Num;
	}
	string GefType() {
		return Type;
	}
	string GefProduct() {
		return Product;
	}
	string GefCharacteristic() {
		return Characteristic;
	}
	string GefGoods() {
		return Goods;
	}
	string GefCount() {
		return Count;
	}
	string GefRAM() {
		return RAM;
	}
	string GefVideocard() {
		return Videocard;
	}
	string GefCPU() {
		return CPU;
	}
private:

	string Num;
	string Type;
	string Product;
	string Characteristic;
	string Goods;
	string Count;
	string RAM;
	string Videocard;
	string CPU;
	string CAM;
};