#include <QApplication>
//#include <iostream>
#include "EnterBox.h"
//#include "ns_MNAS_ValDimension/nm_value.h"
#include "nm_value.h"
#include "method_half_div.h"

nm_value foo_1 (const nm_value & x);

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	EnterBox *mainWin=new EnterBox (0, nm_value(10) );
	mainWin->show();

	return app.exec();
}

/*
  int main(int argc, char **argv)
{
	QTextStream out (stdout);
	out<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
	
	//nm_value FF_nm_value(const nm_value &)
	nm_value rez = Half_Div(nm_value (0.0, "Pa"), nm_value (100.0, "Pa"), nm_value (0.00001, "m"), foo_1);
	out << rez << endl;


	QApplication app(argc, argv);
	EnterBox mainWin(0, nm_value(10) );
	
	mainWin.setExpansion(3);

	
	nm_value a=nm_value (1.0);
	a= a+2.0;
	a=a-1;
	
	nm_value b=nm_value (9.0,"cm3*kg3");
	
	nm_value c=nm_value (1.0,"cm");
	
	nm_value a1,a2;
	a1=nm_value (10, "Pa");
	a2= nm_value (10, "m");
	
	out << a1 <<"=="<< a2 << "->" << (a1==a2) << endl;
	out << a1 <<"!="<< a2 << "->" << (a1!=a2) << endl;
	out << a1 <<"<"<< a2 << "->" << (a1<a2) << endl;
	out << a1 <<">"<< a2 << "->" << (a1>a2) << endl;
	out << a1 <<"<="<< a2 << "->" << (a1<=a2) << endl;
	out << a1 <<">="<< a2 << "->" << (a1>=a2) << endl;
	
//	nm_value abc=a/(b*c);
	nm_value abc=b.pownm2(1, 3);


	mainWin.setValueType("pressure");
	mainWin.setValueType("length");
	mainWin.setVal(abc);
	
	mainWin.setDescription(QString::fromUtf8("Name"));
	mainWin.show();

	return app.exec();
}
 */

nm_value foo_1 (const nm_value & x)
{
	return x*x-5.0;
}

//Half_Div(0.0, 100.0, 0.0001, foo_1);
