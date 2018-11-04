#ifndef NEGOCIO_H_INCLUDE
#define NEGOCIO_H_INCLUDE
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct
{
    int idJuego;
    char descripcion[51];
    float importe;
    int isEmpty;
}eJuego;
typedef struct
{

int id;
char descripcion[51];

}eCategoria;
typedef struct
{
    int idCliente;
    char apellido[51];
    char nombre[51];
    char telefono[21];
    char domicilio[51];
    int isEmpty;

}eCliente;
typedef struct
{
    int isEmpty;
    int idAlquier;
    int idJuego;
    int idCliente;
    eFecha fecha;
}eAlquileres;
void menuPrincipal(int cantiUser,int cantiGame,int cantiCategory, eJuego* game,eCliente* users,eAlquileres* alquiler,eCategoria* category);
void cargarCategorias(eCategoria* categorias, int tamc);
/**
 * \brief indica que todas las posiciones del array estan
 *  habilitadas poniendo todas las banderas(isEmpty) en 1 o true
 * \param eCliente user Lista,estructura del sistema de clientes
 * \param cantidad de veces que debe interar cantidad de clientes
 * \param eJuego game Lista,estructura del sistema de juegos
 * \param cantidad de veces que debe interar cantidad de juegos
 * \param eAlquileres rent Lista,estructura del sistema de alquileres
 */
void init(eCliente* user,int cantidad,eJuego* game,int cantJuego,eAlquileres* rent);
/**
* \brief Obtiene el espacio libre en la que la bandera isEmplty esta en 0
* \param eCliente user Lista , estructra del sistema de clientes
* \param cantidad Total de base de datos del sistema
* \return Retorna la posicion en la que hay espacio libres
*/
int obtenerEspacioLibre(eCliente user[] , int cantidad);
/**
* \brief Obtiene el espacio libre en la que la bandera isEmplty esta en 0
* \param eJuego game Lista , estructra del sistema de juegos
* \param cantidad Total de base de datos del sistema
* \return Retorna la posicion en la que hay espacio libres
*/
int obtenerEspacioLibre2(eJuego game[] , int cantidad);
/**
* \brief Obtiene el espacio libre en la que la bandera isEmplty esta en 0
* \param eAlquileres rent Lista , estructra del sistema de clientes
* \param cantidad Total de base de datos del sistema
* \param cantidad Total de base de datos del sistema de juegos
* \return Retorna la posicion en la que hay espacio libres
*/
int obtenerEspacioLibreAlquiler(eAlquileres* rent , int cantidad,int cantiGame);
int menu();
/**
* \brief agrega a la lista declientes eClientes los datos coloca la bandera IsEmpty en 0
* \param eCliente user Lista , estructra del sistema de clientes
* \param cantidad Total de base de datos del sistema
* \return Retorna (-1) si es error o 0 si fue correcta la carga
*/
int addUser(eCliente* user,int cantidad);
void printUser(eCliente* user,int i);
/**
* \brief busca al cliente por el id en la estructura eCliente
* \param eCliente user Lista , estructra del sistema de cliente
* \param cantidad Total de base de datos del sistema
* \return Retorna -1 si no encontro al cliente su no retorna la posicion del ckiente buscado
*/
void menuDownModific(eCliente* user,int cantidad);
/**
* \brief Remueve al cliente buscado por el Codigo de cliente pone la bandera isEmpty en 1
* \param eCliente user Lista , estructra del sistema de clientes
* \param posID numero exacto donde se encuantra el dato buscado
* \return no retorna ningun valor
*/
void removeUser(eCliente* user,int posID);
int findUserById(eCliente* user, int cantidad,int id);
/**
* \brief modifica al cliente buscado primero preguntando que datos quiere cambiar o si desea salir
* \param eCliente user Lista , estructra del sistema de clientes
* \param index Numero del cliente que se desea modificar
* \return np retorno ningun valor
*/
void modificationUser(eCliente* user,int index);
/**
* \brief Acomoda el array de clientes el order indica si de mayor a menor
*         o de menor a mayor
* \param eCliente user Lista , estructra del sistema de clientes
* \param cantidad Total de base de datos del sistema
* \param order [1] indica de mayor a menor  - [0] indica de menor a mayor
* \return ino retorna ningun valor
*/
void sortUser(eCliente* user, int cantidad ,int order);
void menuDos(eCliente* user,int cantidad);
/**
* \brief agrega a la lista deJuegos eJuegos los datos coloca la bandera IsEmpty en 0
* \param eJuego game Lista , estructra del sistema de juegos
* \param cantidad Total de base de datos del sistema
* \return Retorna (-1) si es error o 0 si fue correcta la carga
*/
int addGame(eJuego* game,int cantidad);
void printGame(eJuego* game,int i);
/**
* \brief busca al juego por el id en la estructura eJuego
* \param eJuego game Lista , estructra del sistema de juego
* \param cantidad Total de base de datos del sistema
* \return Retorna -1 si no encontro al juego su no retorna la posicion del ckiente buscado
*/
void menuDownModificGame(eJuego* game,int cantidad);
/**
* \brief Remueve al juego buscado por el id pone la bandera isEmpty en 1
* \param eJuego game Lista , estructra del sistema de juegos
* \param posID numero exacto donde se encuantra el dato buscado
* \return no retorna ningun valor
*/
void removeGame(eJuego* game,int posID);
int findGameById(eJuego* game, int cantidad,int id);
/**
* \brief modifica al juego buscado primero preguntando que datos quiere cambiar o si desea salir
* \param eJuego game Lista , estructra del sistema de juegos
* \param index Numero del juego que se desea modificar
* \return np retorno ningun valor
*/
void modificationGame(eJuego* game,int index);
/**
* \brief Acomoda el array de juegos el order indica si de mayor a menor
*         o de menor a mayor
* \param eJuego game Lista , estructra del sistema de juegos
* \param cantidad Total de base de datos del sistema
* \param order [1] indica de mayor a menor  - [0] indica de menor a mayor
* \return ino retorna ningun valor
*/
void sortRent(eAlquileres* rent, int cantidad ,int order);
void menuDosRent(eAlquileres* rent,eJuego* game,eCliente* user,int cantiUser,int cantiGame);
/**
* \brief agrega a la lista de clientes eClientes los datos coloca la bandera IsEmpty en 0
* \param eAlquileres rent Lista , estructra del sistema de alquiler
* \param cantidad Total de base de datos del sistema de clietes
* \param cantiGame Total de base de datos del sistema de juegos
* \param eCliente user Lista , estructra del sistema de clientes
* \param eJuego game Lista , estructra del sistema de juegos
* \return Retorna (-1) si es error o 0 si fue correcta la carga
*/
void addRent(eAlquileres* rent,int cantidad,int cantiGame,eCliente* user,eJuego* game);
void printRent(eAlquileres rent,eJuego* game,eCliente* user,int cantidad,int cantiGame);
void cargarNombre(eCliente user[], int cantidad, int idCliente, char cadena[]);
void cargarDescripcion(eJuego game[], int cantidad, int idJuego, char cadena[]);
void sortUserRent(eCliente* user, int cantidad );
int selecUser(eCliente* user, int cantidad);
void sortGameRent(eJuego* game, int cantidad);
int selecGame(eJuego* game, int cantidad);
void GetDay(eAlquileres* rent, int cantidad);
void menuDosGame2(eJuego* game,int cantidad);
void sortGameImport(eJuego* game, int cantidad);
void menuDosUser2(eCliente* user,int cantidad);
void sortUserApellido(eCliente* user, int cantidad );
int promedio(eAlquileres* rent,int cantidad,int cantiGame,eJuego* game);

#endif // NEGOCIO_H_INCLUDE

