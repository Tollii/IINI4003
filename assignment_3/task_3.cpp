#include <string>

const double sales_tax = 1.25;

using namespace std;

class Commodity {
public:
	Commodity(const string &name, int id_, double price_);
	const string &get_name() const;
	const int get_id() const;
	const double get_price(int number_of_items) const;
	const double get_price_with_sales_tax(int number_of_items) const;
	void set_price(double new_price);

private:
	string name;
	int id;
	double price;
};

Commodity::Commodity(const string &name_, int id_, double price_) : name(name_), id(id_), price(price_) {}

const string &Commodity::get_name() const {
	return name;
}

const int Commodity::get_id() const {
	return id;
}

const double Commodity::get_price(int number_of_items = 1) const {
	return price * number_of_items;
}

const double Commodity::get_price_with_sales_tax(int number_of_items = 1) const {
	return price * number_of_items * sales_tax;
}

void Commodity::set_price(double new_price) {
	price = new_price;
}
