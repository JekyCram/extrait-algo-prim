//extrait de l'algo prim
void prim(Coordonnees c, Graphe G)// On entre en argument le point de départ || MAJ: on ne rentre pas le point de départ, on commence tjrs du premier point
{
	Tas t;
	t = new_tas(c->n);//le tas n'est qu'un outil donc on peut l'initialiser seulement dans prim
	
	int i = 0;
	int j = 0;
	//float tableauDist[c->n][c->n];//on calcule une seule fois un grand tableau des distances
	float dist_euclid = 0;
	/*
	for(i = 0; i < c->n; i++)
	{
		for(j = i; j < c->n; j++)
		{
			if(dep != i)
			{
				//on calcule la distance euclidienne entre chaque sommet (tous les sommets entre eux)
				dist_euclid = sqrt(pow((c->clist[j]->coordx - c->clist[i]->coordx),2) + pow((c->clist[j]->coordy - c->clist[i]->coordy),2));
				tableauDist[i][j] = dist_euclid;
				tableauDist[j][i] = dist_euclid;
			}
			else
			{
				tableauDist[i][j] = 0;//on met à zéro les distances entre les mêmes points (exemple: entre le point A et le point A)
				tableauDist[j][i] = 0;
			}
		}
		tableauDist[i][i] = 0;
		insert(&T,i,tableauDist[dep][i]);//les tas sont triés depuis le point de départ
	}
	int temp = dep;
	while( !(est_vide(T)))//tant que la liste n'est pas vide
	{
		int minDist = 10000000;
		for(i=0 ; i<(c->n) ; i++)
		{
			//on cherche le plus petit élément dans le liste de sommets
			if(tableauDist != 0 && tableauDist[dep][j] != -1 && tableauDist[dep][j] < minDist)
			{
				minDist	= tableauDist[dep][j];
				temp = i; //on garde en mémoire le point le plus près pour ensuite en repartir (le désigner comme point de départ)					}
			}
		}
		//à partir de ce point, on connait le lieu le plus proche
		for(i = 0 ; 1< c->n ; i++)
		{
			tableauDist[dep][i] = -1;// le -1 signifie que l'on est déjà passé par le sommet et qu'on raye le point du tableau
			tableauDist[i][dep] = -1;
		}
		graphe_ajouter_arete(*G,dep,temp);
		
		//on ajoute un degré car on a relié deux sommet => on ajoute n degré à ces deux sommets
		G->alist[temp]->d ++;
		G->alist[dep]->d ++;sqt
		
		dep = temp; //le point où on est arrivés deviens à nouveau le point de départ
		temp = 10000000;
	}
	*/
	
	for(i = 0 ; i<c->n ; i++)//peut être besoin de commencer à 1 car distance entre le point 0 et le point 0 = problèmes
	{
		//on initialise les éléments du tas à partir du sommet 0
		dist_euclid = sqrt(pow((c->clist[i]->coordx - c->clist[0]]->coordx),2) + pow((c->clist[i]->coordy - c->clist[0]->coordy),2));
		insert(t,0,i,dist_euclid)//on insert les éléments du tas selon leur: tas,s1,s2,priorité
	}
	//tous nos éléments du tas sont triés par distance croissante par rapport au point 0
	
	graphe_ajouter_arete(g,t->pos[1]->s1/*on récupère le sommet dans la structure tas*/,t->pos[1]->s2/*on récupère le s2 dans la structure du tas*/);
	//on vient d'ajouter la première arête
	int temp = t->tab[1]->s2 //on prend comme futur point de départ le sommet 2
	supp(t, t->tab[1]);//le premier élément a été supprimé
	
	while(!(est_vide(t)))
	{	
		for(i = temp ; i<c->n ; i++)// on commence depuis le nouveau point de départ désigné
		{
			dist_euclid = sqrt(pow((c->clist[i]->coordx - c->clist[temp]->coordx),2) + pow((c->clist[i]->coordy - c->clist[temp]->coordy),2));
			if(t->priorite[i] < dist_euclid)
			{
				supp(t,i);//on supprime l'élément qui est désormais obsolète au niveau de la priorité
				insert(t,temp,i,dist_euclid);//on ajoute de nouveau l'élément mis à jour pour les distances
			}
		}
		//à la fin de cette boucle, on a mis à jour les priorités des éléments, pn peut donc ajouter la prochaine arête (la plus proche du dernier sommet)
		graphe_ajouter_arete(g,t->priorite[1]->s1,t->priorite[1]->s2);//on ajoute la prochaine arête
		supp(t, t->tab[1]);//on supprime le premier élément du tas, puis on recommence
	}
}
