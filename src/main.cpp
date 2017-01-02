#include <QApplication>
#include "EnterBox.h"
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

nm_value foo_1 (const nm_value & x)
{
  return x*x-5.0;
}

//Half_Div(0.0, 100.0, 0.0001, foo_1);
