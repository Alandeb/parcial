#include <stdio.h>
#include <stdlib.h>
#include "negocio.h"
#include "validaciones.h"
#define CANTUSER 100
#define CANTGAME 20
#define CANTCATEGO 5

int main()
{
    eJuego game[CANTGAME];
    eCliente users[CANTUSER];
    eAlquileres alquiler[CANTUSER*CANTGAME];
    eCategoria category[CANTCATEGO];
    menuPrincipal(CANTUSER,CANTGAME,CANTCATEGO,game,users,alquiler,category);
    return 0;
}
