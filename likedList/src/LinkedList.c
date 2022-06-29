#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this!=NULL){
    	this->size=0;
    	this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if (this!=NULL) {

    	returnAux=this->size;
	}

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int len_linkedList;

	if(this!=NULL )
	{
        len_linkedList=ll_len(this);
		if (nodeIndex>=0 && nodeIndex<len_linkedList) {

			pNode = this->pFirstNode;
			for (int index = 0;  pNode->pNextNode!=NULL ; index++) {

				if (index==nodeIndex) {
					break;
				}else{
					pNode = pNode->pNextNode;
				}
			}
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len_linkedList;
    Node* newNodo=NULL;
    Node* anteriorNodo=NULL;

    if(this!=NULL )
    {
    	len_linkedList=ll_len(this);
    	if ( nodeIndex>=0 && nodeIndex<=len_linkedList) {

			newNodo = (Node*) malloc(sizeof(Node));
			if (newNodo!=NULL) {

				if (nodeIndex==0) {

					newNodo->pNextNode=this->pFirstNode;
					this->pFirstNode=newNodo;
				}
				else{
					anteriorNodo = getNode(this, (nodeIndex-1));
					if (anteriorNodo!=NULL) {

						newNodo->pNextNode= anteriorNodo->pNextNode;
						anteriorNodo->pNextNode = newNodo;
					}
				}
				newNodo->pElement=pElement;
				this->size++;
				returnAux =0;
			}
			//pNodo = getNode(this, nodeIndex);
		}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int lastNode;

    if (this!=NULL) {

    	if ((lastNode = ll_len(this))>=0) {

			if (!addNode(this,lastNode , pElement)) {

				returnAux=0;
			}
		}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;

    if(this !=NULL && index>=0 && index<ll_len(this))
    {
    	if ((pNode=getNode(this, index))!=NULL) {

    		returnAux=pNode->pElement;
		}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	int returnAux = -1;
    Node* pNode;

    if(this !=NULL && index>=0 && index<ll_len(this))
    {
    	if ((pNode=getNode(this, index))!=NULL) {
    		pNode->pElement=pElement;
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pAnteriorNodo;
    Node* pNodoEliminar;
    if(this !=NULL && index>=0 && index<ll_len(this))
    {
    	pNodoEliminar=getNode(this, index);
    	if (pNodoEliminar!=NULL) {

    		if (index==0) {
    			this->pFirstNode=pNodoEliminar->pNextNode;
			}
    		else{

				pAnteriorNodo=getNode(this, index-1);
				if (pAnteriorNodo!=NULL) {

					pAnteriorNodo->pNextNode=pNodoEliminar->pNextNode;
				}
    		}
    		this->size--;
    		free(pNodoEliminar->pElement);
    		free(pNodoEliminar);
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int returnAux = -1;
	int len_linkedList=ll_len(this);

	if (this!=NULL && len_linkedList > 0) {

		for (int index = len_linkedList; index >= 0; index--) {

			if (!ll_remove(this, index)) {

				returnAux=0;
			}
		}
	}
	return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL && !(ll_clear(this)))
    {
    	this=NULL;
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len_linkedList=ll_len(this);
    void* pElementoAux;

    if (this!=NULL) {

    	for (int index = 0; index < len_linkedList; index++) {

    		pElementoAux=ll_get(this, index);
    		if (pElementoAux == pElement) {
    			returnAux=index;
    			break;
			}
		}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if (this!=NULL) {

    	returnAux=0;
    	if (!ll_len(this)) {
    		returnAux=1;
		}
	}
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len_linkedList;

    if(this!=NULL )
    {
    	len_linkedList=ll_len(this);
    	if (index>=0 && index<=len_linkedList) {

			if(!(addNode(this,index,pElement)))
			{
				returnAux=0;
			}
		}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if (this!=NULL) {

    	returnAux = ll_get(this, index);
    	if (returnAux!=NULL) {

    		ll_remove(this, index);
		}
	}
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len_linkedList;
    int indice;

   	if (this!=NULL) {

   		returnAux=0;
   		len_linkedList=ll_len(this);
   		if ((indice = ll_indexOf(this, pElement))>=0 ) {

			for (int i = 0; i < len_linkedList; i++) {
				if ( indice == i ) {
					returnAux=1;
					break;
				}
			}
		}
   	}
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElementoAux2;
    int len_linkedList2;

	if (this!=NULL && this2!=NULL) {

		len_linkedList2=ll_len(this2);
		returnAux=1;
		for (int index2 = 0; index2 < len_linkedList2; index2++) {

			pElementoAux2= ll_get(this2, index2);
			if (!ll_contains(this, pElementoAux2)) {

				returnAux=0;
				break;
			}
		}
	}
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray =NULL;
    int len_linkedList;
    void* pElemento;

    if (this!=NULL && from>=0 && to>from ) {

    	len_linkedList = ll_len(this);
    	if (to<=len_linkedList) {

    		cloneArray =ll_newLinkedList();

			for (int i = from; i<to; i++) {

				pElemento = ll_get(this, i);
				if (pElemento!=NULL) {

					ll_add(cloneArray, pElemento);
				}
			}
		}
	}
    return cloneArray;
}
/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if (this!=NULL) {
    	cloneArray = ll_subList(this, 0, ll_len(this));
	}
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;
	int i;
	int flagSwap = 1;
	int criteria;
    int len_linkedList;
	void* pElement;
	void* pElement2;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		len_linkedList = ll_len(this);

		if( len_linkedList >=0){
			do
			{
				flagSwap = 0;
				for (i=0; i<len_linkedList-1; i++)
				{
					pElement = ll_get(this,i);
					pElement2 = ll_get(this,i+1);
					criteria = pFunc(pElement,pElement2);
					if ((order == 1 && criteria == 1) ||
						(order == 0 && criteria == -1))
					{
						ll_set(this,i,pElement2);
						ll_set(this,i+1,pElement);
						flagSwap = 1;
					}
				}
			}while (flagSwap);
			returnAux = 0;
		}
	}
    return returnAux;

}

