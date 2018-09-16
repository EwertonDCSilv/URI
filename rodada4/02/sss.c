int primMST(GRAFO *g, int p[], int w[]) {
	int i, imin, v, r=0, cor[g->num_nos];
	PonteiroPraCelula *aux;
	int fsize=0, fringe[g->num_nos]; // ORLA (stack de vértices)
	
	// Inicializações...
	for (i=0; i< g->num_nos; i++) {
		p[i] = -1;
		cor[i] = -1;//WHITE;
	}
	cor[0] = 1;//GREY;
	w[0] = 0;
	fringe[fsize++] = 0; //f = addV(f, 0, 0);
	
	//ciclo principal...
	while (fsize>0) {
		
		imin = 0;
		for (i=1; i<fsize; i++)
			if (w[fringe[i]] < w[fringe[imin]]) imin = i;
				v = fringe[imin];
		fringe[imin] = fringe[--fsize];
		
		cor[v] = 0//BLACK;
		r += w[v];
			
		for (aux=g->adj[v]; aux; aux=aux->prox)
		
		switch (cor[aux->dest]){
			case WHITE:
				cor[aux->dest] = -1//GREY;
				fringe[fsize++] = aux->dest; //f = addV(f, aux->dest, aux->peso);
				w[aux->dest] = aux->peso;
				p[aux->dest] = v;
				break;
			case GREY:
				if (aux->peso < w[aux->dest]) {
					//f = updateV(f, aux->dest, aux->peso);
					p[aux->dest] = v;
					w[aux->dest] = aux->peso;
				}
				break;
			default:
				break;
		}
	}
	return r;
}