#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "negocio.h"
#include "validaciones.h"
/**
 * \brief escanea un entero y lo guarda en un puntero
 * \param pBuffer puntero donde se va a guardar el dato
 * \return Retorna true o false dependiendo si scan consigue un dato
 *
 */
int getInt(int* pBuffer)
{
    fflush(stdin);
    return scanf("%d",pBuffer);
}
/**
 * \brief escanea un flotante y lo guarda en un puntero
 * \param pBuffer puntero donde se va a guardar el dato
 * \return Retorna true o false dependiendo si scan consigue un dato
 *
 */
int getFloat(float* pBuffer)
{
    fflush(stdin);
    return scanf("%f",pBuffer);
}
/**
 * \brief escanea un caracter y lo guarda en un puntero
 * \param msg Mensaje a ser mostrado
 * \param pBuffer puntero donde se va a guardar el dato
 * \return Retorna true o false dependiendo si scan consigue un dato
 */
void getString(char msg[],char* pBuffer)
{
    printf("%s",msg);
    fflush(stdin);
    fgets(pBuffer, 51 , stdin);
    pBuffer[strcspn(pBuffer, "\n")] = 0;
}
/**
 * \brief escanea un caracter y lo guarda en un puntero
 * \param msg Mensaje a ser mostrado
 * \param pBuffer puntero donde se va a guardar el dato
 * \return Retorna true o false dependiendo si scan consigue un dato
 */
void getString21(char msg[],char* pBuffer)
{
    printf("%s",msg);
    fflush(stdin);
    fgets(pBuffer, 21 , stdin);
    pBuffer[strcspn(pBuffer, "\n")] = 0;
}
/**
 * \brief escanea un caracter y lo guarda en un puntero
 * \param pBuffer puntero donde se va a guardar el dato
 * \return Retorna true o false dependiendo si scan consigue un dato
 */
int getCaracter(char* pBuffer)
{
    fflush(stdin);
    return scanf("%c",pBuffer);
}
/**
 * \brief Solicita un flotante  al usuario ,lo valida  y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgErr Es el mensaje a ser mostrado si falla el primer ingreso
 * \param pFlotante Puntero donde se guardara el dato ingresado
 * \param min Minimo del numero entero que necesito como condicion
 * \return 0 si el enterp que ingresaron esta entre los numeros de condicion
 */
int utn_getFloat(float *pFlotante, char* msg ,char* msgErr,int min)
{
    int retorno=-1;
    float bufferFloat;
    char bufferFloatString[256];
    if(pFlotante != NULL && msg != NULL && msgErr != NULL&& min >= 1)
    {
        do
        {
            getString(msg,bufferFloatString);
            if( esNumericoFlotante(bufferFloatString))
            {
                bufferFloat = atof (bufferFloatString);
                if(bufferFloat >= min){
                    *pFlotante = bufferFloat;
                    retorno = 0;
                    break;
                }
            }
            else
            {
                fflush(stdin);
                msg=msgErr;
            }
        }while(retorno!=0);
    }
    return retorno;
}
/**
 * \brief Verifica si el valor recibido es numérico flotante
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int esNumericoFlotante(char str[])
{
   int i=0,flagcoma=0;
   if(str[i] == '\0')
        return  0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9'){
            if(str[i]==','||str[i]=='.'){
                if(flagcoma==1){
                    return 0;
                }else
                    flagcoma=1;
            }else
                return 0;
        }

       i++;
   }
   return 1;
}
/**
 * \brief Verifica si el valor recibido es numérico entero
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int esNumerico(char str[])
{
   int i=0;
   if(str[i] == '\0')
        return 0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
/**
 * \brief Solicita un entero al usuario ,lo valida  y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgErr Es el mensaje a ser mostrado si falla el primer ingreso
 * \param pEntero Puntero donde se guardara el dato ingresado
 * \param min Minimo del numero entero que necesito como condicion
 * \param max Maximo del numero entero que necesito como segunda condicion
 * \return 0 si el entero que ingresaron esta entre los numeros de condicion
 */
int utn_getEntero(  int* pEntero, char* msg,char* msgErr,int min, int max)
{
    int retorno=-1;
    int bufferInt;
    char bufferIntString[256];
    if(pEntero != NULL && msg != NULL && msgErr != NULL&& min <= max)
    {
        do
        {
            getString(msg,bufferIntString);
            if( esNumerico(bufferIntString))
            {
                bufferInt = atoi(bufferIntString);
                if((bufferInt >= min && bufferInt <= max)){
                    *pEntero = bufferInt;
                    retorno = 0;
                    break;
                }
            }
            fflush(stdin);
            msg=msgErr;
        }while(retorno!=0);

    }
    return retorno;
}
/**
 * \brief Solicita un entero al usuario ,lo valida  y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgErr Es el mensaje a ser mostrado si falla el primer ingreso
 * \param pEntero Puntero donde se guardara el dato ingresado
 * \param min Minimo del numero entero que necesito como condicion
 * \param max Maximo del numero entero que necesito como segunda condicion
 * \return 0 si el entero que ingresaron esta entre los numeros de condicion
 */
int utn_getEnteroEsc(  int* pEntero, char* msg,char* msgErr,int min, int max,int esc)
{
    int retorno=-1;
    int bufferInt;
    char bufferIntString[256];
    if(pEntero != NULL && msg != NULL && msgErr != NULL&& min <= max)
    {
        do
        {
            getString(msg,bufferIntString);
            if( esNumerico(bufferIntString))
            {
                bufferInt = atoi(bufferIntString);
                if((bufferInt >= min && bufferInt <= max)){
                    *pEntero = bufferInt;
                    retorno = 0;
                    break;
                }
                if(bufferInt==esc)
                    break;
            }
            else
            {
                fflush(stdin);//limpia en linux como fflush
                msg=msgErr;
            }
        }while(retorno!=0);

    }
    return retorno;
}
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    int retorno = 1;
    if(str[i] == '\0')
        retorno = 0;
    else{
        while(str[i] != '\0')
        {
            if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgErr Es el mensaje a ser mostrado si falla el primer ingreso
 * \param pBuffer Array donde se cargará el texto ingresado
 * \return 0 si el texto contiene solo letras
 */
int getStringLetras(char* msg,char* msgErr,char* pBuffer)
{
    char aux[51];
    int retorno=-1;
    do{
        getString(msg,aux);
        if(esSoloLetras(aux))
        {
            strcpy(pBuffer,aux);
            retorno=0;
            break;
        }
     msg=msgErr;
    }while(retorno!=0);
    return retorno;
}
/**
 * \brief Solicita un caracter al usuario ,lo valida  y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgErr Es el mensaje a ser mostrado si falla el primer ingreso
 * \param pCaracter char donde se cargará el texto ingresado
 * \param letraUno caracter que necesito como condicion
 * \param letraDos caracter que necesito como segunda condicion
 * \return 0 si el caracter que ingresaron en igual al que se colo como condicion
 */
int utn_getCaracter(  char* pCaracter, char* msg,char* msgErr,char letraUno,char letraDos)

{
    int retorno=-1,devuelve;
    char bufferChar;
    if( msg != NULL && msgErr != NULL&& (letraUno>=0||letraUno<=255)&& (letraDos>=0||letraDos<=255) )
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            devuelve=getCaracter(&bufferChar);
            bufferChar=tolower(bufferChar);
            if( ( devuelve == 1)&&(bufferChar == letraUno || bufferChar == letraDos))
            {
                *pCaracter = bufferChar;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                msg=msgErr;
            }
        }while(retorno!=0);

    }
    return retorno;
}
/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0,retorno=1;
   if(str[i] == '\0'){
        retorno = 0;
   }else{
        while(str[i] != '\0')
        {
            if((str[0] != '+') && (str[i] != '-') && (str[i] < '0' || str[i] > '9')){
                retorno=0;
                break;
            }
            i++;
        }
   }
    return retorno;
}
/**
 * \brief Solicita un telefono al usuario y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgErr Es el mensaje a ser mostrado si falla el primer ingreso
 * \param pBuffer Array donde se cargará el texto ingresado
 * \return 0 si el texto contiene solo letras
 */
int getStringTelefono(char* msg,char* msgErr,char* pBuffer)
{
    char aux[21];
    int retorno=-1;
    do{
        getString21(msg,aux);
        if(esTelefono(aux))
        {
            strcpy(pBuffer,aux);
            retorno=0;
            break;
        }
     msg=msgErr;
    }while(retorno!=0);
    return retorno;
}
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   if(str[i] == '\0'){
        return 0;
   }else{
        while(str[i] != '\0')
        {
            if((str[i]!=' ')&&(str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
                return 0;
            i++;
        }
   }
   return 1;
}
/**
 * \brief Solicita un telefono al usuario y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgErr Es el mensaje a ser mostrado si falla el primer ingreso
 * \param pBuffer Array donde se cargará el texto ingresado
 * \return 0 si el texto contiene solo letras
 */
int getStringAlfaNumerico(char* msg,char* msgErr,char* pBuffer)
{

    char aux[51];
    int retorno=-1;
    do{
        getString(msg,aux);
        if(esAlfaNumerico(aux))
        {
            strcpy(pBuffer,aux);
            retorno=0;
            break;
        }
     msg=msgErr;
    }while(retorno!=0);
    return retorno;
}
