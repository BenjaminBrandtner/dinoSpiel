/*Autor: Philipp Hägeirich
Kolisionsabfrage für dino*/

bool kolision(int Ydino, int Xkaktus; struct tex_rest *dino,struct tex_rest *kaktus) //Xdino=10 und Ykaktus=32
{
	int Xdino=10;
	int Ykaktus=32;
	int gemeinsamme_reihen, gemeinsamme_spalten;
	int i, j;
	
	gemeinsamme_spaltens = Ykaktus - Ydino + 21;
	gemeinsamme_reihen = Xkaktus - Xdino + 18;
	
	if(geimensamme_spalten>=0)
	{
		for(i=0;i<gemeinsamme_spalten;i++) //für dino 21-gemeinsamme_spalten+i
		{
			if(gemeinsamme_reihen>=0)
			{
				for(j=0;j<gemeinsamme_reihen;j++) //für dino 18-gemeinsamme_reihen+j
				{
					if((*dino).textur[18-gemeinsamme_reihen+j][21-gemeinsamme_spalten+i]==(*kaktus).textur[j][i] && (*kaktus).textur[j][i]=='#')
					{
						return true;
					}
				}
			}
			else
			{
				for(j=0;j<gemeinsamme_reihen;j++) //für dino 18-j
				{
					if((*dino).textur[18-j][21-gemeinsamme_spalten+i]==(*kaktus).textur[j][i] && (*kaktus).textur[j][i]=='#')
					{
						return true;
					}
				}
			}
		}
	}
	else
	{
		for(i=21;i>(gemeinsamme_spalten*-1);i--) //für dino 21-i
		{
			if(gemeinsamme_reihen>=0)
			{
				for(j=0;j<gemeinsamme_reihen;j++) //für dino 18-gemeinsamme_reihen+j
				{
					if((*dino).textur[18-gemeinsamme_reihen+j][21-i]==(*kaktus).textur[j][i] && (*kaktus).textur[j][i]=='#')
					{
						return true;
					}
				}
			}
			else
			{
				for(j=0;j<gemeinsamme_reihen;j++) //für dino 18-j
				{
					if((*dino).textur[18-j][21-i]==(*kaktus).textur[j][i] && (*kaktus).textur[j][i]=='#')
					{
						return true;
					}
				}
			}
		}
	}
	
	return false;
}