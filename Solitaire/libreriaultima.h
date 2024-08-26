using namespace std;

struct nodo{
   int clave;        // en este caso es un numero entero
   int pinta;
   char color;
   bool mostrar;
   struct nodo *prox; 
};

struct lprincipal{
    int posicion;        // en este caso es un numero entero
    struct lprincipal *prox;
    struct nodo *carta;
};

typedef struct lprincipal *Tprincipal; 
typedef struct nodo *Tlista;

bool esVacia(Tlista &lista) {
    bool log = false;
    if (lista==NULL) log= true;
    return log;
} 

/*void insertarInicio(Tlista &lista, Tlista &aux)
{
        Tlista q;
        q = new(struct nodo);
        q->clave = aux->clave;
        q->pinta = aux->pinta;
        q->prox = lista;
        lista  = q;
}
*/ 

void insertarFinal(Tlista &lista, Tlista &aux) {
    Tlista t, q = new(struct nodo);
 
    q->clave  = aux->clave;
    q->pinta = aux->pinta;
    q->mostrar =true;
    if (q->pinta <= 2) q->color = 'R';
    else q->color = 'N';

    q->prox = NULL;
 
    if(lista==NULL) lista = q;

    else {
        t = lista;
        while(t->prox!=NULL) t = t->prox;
        t->prox = q;
    }
}
void eliminarDeLaListaActual(Tlista &lista){
	Tlista aux;
	aux = lista;
    lista = lista->prox;
    delete aux;
}
void imprimirElemento(Tlista elemento){
    if (elemento->pinta == 1)
    cout<< elemento->clave<<","<< "C"<< endl;
    if (elemento->pinta == 2)
    cout<< elemento->clave<<","<< "D"<< endl;
    if (elemento->pinta == 3)
    cout<< elemento->clave<<","<< "P"<< endl;
    if (elemento->pinta == 4)
    cout<< elemento->clave<<","<< "T"<< endl;
}
void imprimirMazo(Tprincipal l){
    Tlista q;
    Tprincipal aux = l;
    while(aux != NULL){
    	if(aux->carta != NULL){
    		q = aux->carta;
    		cout<< aux->posicion<< endl;
    		while (q != NULL){
      			imprimirElemento(q);
      			q = q->prox;
    		}
    	}
    	aux = aux->prox;
	}
}

bool existeElementoClave(Tlista lista, int clave, int pinta){
    Tlista q;
    bool log = false;
    q = lista;
    while(q != NULL) {
        if(q->clave==clave && q->pinta==pinta) {
            log = true;
            break;
        }
        q = q->prox;
    }
return(log);
}
Tlista buscarElemento(Tprincipal l, int valor, int pinta) {
    Tprincipal q = l;
    while(q != NULL) {
        Tlista c = q->carta;
        while(c->prox != NULL){
            if ((c->clave == valor) && (c->pinta == pinta)) return(c);
            else c = c->prox;
        }
        q = q->prox;
    }
}
bool verificarMovilidad (int clave, int pinta, int columna, Tprincipal l){
    Tlista c = buscarElemento(l,clave,pinta);
    if (c->mostrar == false) return false; //Si la carta no está visible retorna falso
    else{
        Tprincipal q = l;
        Tlista aux;
        while( q->posicion != columna ) q = q->prox;
        aux = q->carta;
        if ((columna >= 2)&&(columna <= 8)){
            if ((aux == NULL)&&(c->clave = 13))return true;

            else if ((aux != NULL) && (c->clave < 13)){
                while (aux != NULL) aux = aux->prox;
                if ((aux->clave == c->clave + 1) && (c->color != aux->color)) return true;
            }
            else return false;
        }
        else if (columna >= 9){
            if (((columna == 9) && (c->pinta == 1))||((columna == 10) && (c->pinta == 2))||((columna == 11) && (c->pinta == 3))||((columna == 12) && (c->pinta == 4))){
                if(aux != NULL){
                    while (aux != NULL) aux = aux->prox;
                    if (aux->clave == c->clave + 1) return true;
                    else return false;
                }
                else if ((aux == NULL) && (c->clave == 13)) return true;
                else return false;
            }
            else return false;
        }
    }
}
void listaPrincipal(Tprincipal &l){ //Crea la lista que contiene a todas las listas(mazo,l1,l2,l3,l4,l5,l6,l7,C,P,D,T)
	int i = 12;
	Tprincipal t;
	while (i >= 1){
		Tprincipal q = new (struct lprincipal);
		q->posicion = i;
        q->prox = l;
		l = q;
		i--;
	}
}
void crearMazo (Tprincipal &l){
	listaPrincipal(l);
    l->carta = NULL;
    int clave,pinta,i;
    i = 1;
    Tlista lista = new(struct nodo);
    lista = NULL;
    while (i <= 52){
        clave=1+rand()%(14-1);//Genera numero aleatorio
        pinta=1+rand()%(5-1); //Genera numero aleatorio
        Tlista aux = new(struct nodo);
        aux->clave = clave;
        aux->pinta = pinta;
        //if(i==1) cout<< lista->clave<< lista->pinta;
        if(existeElementoClave(lista, clave, pinta) == false){ //En caso de que no esté
            insertarFinal(lista, aux);
            i++; 
        }   
    }
    l->carta = lista; 
}
void distribuirMazo(Tprincipal l){
    Tlista f,  m;
    Tprincipal q = l;
    int i = 2;
    m = l->carta;
    q = q->prox;
    while (i <= 8){
        int c = 2;
        f = q->carta;
        while(c <= i){ // si  C = I entonces tenemos que imprimir el valor, de lo contrario imprimir X ( oculto o )
        	insertarFinal(f, m);
        	eliminarDeLaListaActual(m);
          	c++;
        }
        q->carta = f;
        q = q->prox;
    	i++;
    }
    l->carta = m;
}