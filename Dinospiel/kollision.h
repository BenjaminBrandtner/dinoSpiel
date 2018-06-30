/*Autor: Philipp Hägeirich
Kolisionsabfrage für dino*/

bool kollision(int Ydino, int Xkaktus, struct tex_rest dinoL,struct tex_rest kaktusL) //Xdino=10 und Ykaktus=32
{
	int Xdino=10;
	int Ykaktus=32;
	int gemeinsame_reihen, gemeinsame_spalten;
	int i, j;
	
	gemeinsame_spalten = Ykaktus - Ydino + 21;
	gemeinsame_reihen = Xkaktus - Xdino + 18;
	
	if(gemeinsame_spalten>=0)
	{
		for(i=0;i<gemeinsame_spalten;i++) //für dino 21-gemeinsame_spalten+i
		{
			if(gemeinsame_reihen>=0)
			{
				for(j=0;j<gemeinsame_reihen;j++) //für dino 18-gemeinsame_reihen+j
				{
					if(dinoL.textur[18-gemeinsame_reihen+j][21-gemeinsame_spalten+i]==kaktusL.textur[j][i] && kaktusL.textur[j][i]=='#')
					{
						return true;
					}
				}
			}
			else
			{
				for(j=0;j<gemeinsame_reihen;j++) //für dino 18-j
				{
					if(dinoL.textur[18-j][21-gemeinsame_spalten+i]==kaktusL.textur[j][i] && kaktusL.textur[j][i]=='#')
					{
						return true;
					}
				}
			}
		}
	}
	else
	{
		for(i=21;i>(gemeinsame_spalten*-1);i--) //für dino 21-i
		{
			if(gemeinsame_reihen>=0)
			{
				for(j=0;j<gemeinsame_reihen;j++) //für dino 18-gemeinsame_reihen+j
				{
					if(dinoL.textur[18-gemeinsame_reihen+j][21-i]==kaktusL.textur[j][i] && kaktusL.textur[j][i]=='#')
					{
						return true;
					}
				}
			}
			else
			{
				for(j=0;j<gemeinsame_reihen;j++) //für dino 18-j
				{
					if(dinoL.textur[18-j][21-i]==kaktusL.textur[j][i] && kaktusL.textur[j][i]=='#')
					{
						return true;
					}
				}
			}
		}
	}
	
	return false;
}
