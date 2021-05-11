#include <iostream>

#include "invoice.h"

int main()
{
    Client client{"João António", "Mealhada"};
    Invoice invoice{&client};

    Product computer{"Computer", 999.90};
    Item i{&computer, 10};
    invoice.addItem(i);

    Product p{"Printer", 149.90};
    invoice.addProduct(p);

    invoice.print(std::cout);
}
