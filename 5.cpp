#include <Windows.h>
#include <iostream>
#include "product.h"
#include "products.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    product p1("phone"), p2("mac"), p3("notebook"), p4("ps4"), p5("xbox"), p6;
    products_list pl1;
    pl1.check_void();
    pl1.add(p1);
    pl1.add(p2);
    pl1.add(p3);
    pl1.add(p4);
    pl1.add(p5);
    pl1.add(p6);

    pl1.AllOutAttack();
    pl1.check_void();
    pl1.sale_price();
    pl1.delthis(p6);
    pl1.expen();
    cout << "Товаров больше 100 - " << pl1.count_exp() << endl;
    pl1.reorg();
    pl1.search(p4);
    pl1.AllOutAttack();
    pl1.name_s();
    pl1.AllOutAttack();
    pl1.rev();
    pl1.AllOutAttack();
    pl1.cle();
    pl1.check_void();

    system("pause");
    return 0;
}