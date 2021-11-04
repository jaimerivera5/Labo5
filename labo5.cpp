#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
            int nro;   
            struct nodo *sgte; 
            };

typedef struct nodo;
nodo *fin;
nodo *lista;

void menu1();
void insertarInicio();
void mostrar();
void eliminarElemento();

int main(void)
{
    lista = NULL;
    int op;     


    system("color 0a");

    do
    {
        menu1();
        cin>>op;

        switch(op)
        {
            case 1:
                    insertarInicio();
                    break;


            case 2:
                    cout<<"\n\n Lista Circular \n\n";
                    mostrar();
                    break;


            case 3:
                    eliminarElemento();
                    break;


            default: cout<<"OPCION NO VALIDA...!!!";
                     break;


        }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=7);

   return 0;
}



void menu1()
{
    cout<<"\n\t\tLISTA CIRCULAR\n\n";
    cout<<" 1. INSERTAR ID, NOMBRE DEL DUENO, RAZA, PESO y EDAD DE LA MASCOTA "<<endl;
    cout<<" 2. MOSTRAR LISTA                                                  "<<endl;
    cout<<" 3. ELIMINAR ELEMENTO                                              "<<endl;
    cout<<" 4. SALIR                                                          "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

void insertarInicio()
{
   nodo *nuevo;
   nuevo=new struct nodo;

   cout<<"\n***INSERTA AL INICIO*****\n";
   cout<<"\nINGRESE DATO:";
   cin>>nuevo->nro;
   nuevo->sgte=NULL;

   if(lista==NULL)
    {
        cout<<"PRIMER ELEMENTO..!!!";
        lista=nuevo;
        lista->sgte=lista;
        fin=nuevo;
      }
   else
     {
        nuevo->sgte = lista;
        lista = nuevo;
        fin->sgte = lista;
     }

}

void mostrar()
{   nodo *aux;
    aux=lista;
    int i=1;

    if(lista!=NULL)
     {
          do
          {    cout<<"  "<<aux->nro;
               aux = aux->sgte;
               i++;
          }while(aux!=lista);
      }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;


}

void eliminarElemento()
{
    nodo *aux, *r, *q;
    int i = 1, flag = 0,valor;

    cout<<"\n INGRESE ELEMENTO A ELIMINAR:";
    cin>>valor;

    if(lista !=NULL)
     {
          aux = lista;

          do
          {
               if(aux->nro == valor)
                {
                    if(aux==lista)
                    {   r=lista;
                        lista=lista->sgte;
                        aux=aux->sgte;
                        fin->sgte=lista;
                        r->sgte=NULL;
                        if(fin->sgte==NULL)
                        {
                            lista==NULL;
                            aux==NULL;
                            delete(r);
                            cout<<"\nELEMENTO ELIMINADO...!!!\n";
                            return;
                        }
                        else
                        {
                            delete(r);
                            cout<<"\nELEMENTO ELIMINADO...!!!\n";
                            return;
                        }
                    }
                   else
                    {
                        if(aux==fin)
                            {
                            r=aux;
                            aux=aux->sgte;
                            q->sgte=aux;
                            fin=q;
                            r->sgte=NULL;
                            delete(r);
                            cout<<"\nELEMENTO ELIMINADO...!!!\n";
                            return;
                            }
                        else
                        {
                            r=aux;
                            aux=aux->sgte;
                            q->sgte=aux;
                            r->sgte=NULL;
                            delete(r);
                            cout<<"\nELEMENTO ELIMINADO...!!!\n";
                            return;
                        }
                  }
                  flag=1;
                }
                else
                {   q=aux;
                    aux = aux->sgte;
                    i++;
                }
          }while(aux!=lista);

          if(flag==0)
          cout<<"\n\n\tNumero no econtrado..!"<<endl;


    }
    else
      cout<<"LISTA VACIA...!!!!";


}