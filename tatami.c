void 
tatami(Monitor *m) {
	unsigned int i, n, nx, ny, nw, nh,
				 mats, tc,
				 tnx, tny, tnw, tnh, bw, oe = enableoutergaps, ie = enableinnergaps;
	Client *c;

	for(n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), ++n);
	if(n == 0)
		return;
	
	if (enableoutergaps == 0)
		oe = 0; // outer gaps disabled

	if (enableinnergaps == 0)
		ie = 0; // inner gaps disabled

	if (n == 1) {
		bw = 0;
		oe = 0; // outer gaps disabled
		ie = 0;
	} else {
		bw = borderpx;
	}

	nx = m->wx;
	ny = m->wy;
	nw = m->ww;
	nh = m->wh;
	
	c = nexttiled(m->clients);
	
	if(n != 1)  nw = m->ww * m->mfact;
		ny = m->wy;
				
	resize(c, nx + (m->gappoh * oe), ny + (m->gappov*oe), nw - (2*bw) - (m->gappih*ie/2) - m->gappoh*oe, nh - (2 * bw) - (2*m->gappov*oe), bw, False);
	
	c = nexttiled(c->next);
	
	nx += nw;
	nw = m->ww - nw;
	
	if(n>1)
	{
	
		tc = n-1;
		mats = tc/5;
	
		nh/=(mats + (tc % 5 > 0));
	
		for(i = 0; c && (i < (tc % 5)); c = nexttiled(c->next)) {
			tnw=nw;
			tnx=nx;
			tnh=nh;
			tny=ny;
			switch(tc - (mats*5)) {
				case 1://fill
					tny+=m->gappov*oe;
					tnx= tnx + (m->gappih*ie/2);
					tnw = tnw - (m->gappih*ie/2) - (m->gappoh*oe);
					tnh-=2*m->gappov*oe;
					break;
				case 2://up and down
					if((i % 5) == 0) { //up
						tnw = tnw - (m->gappih*ie/2) - (m->gappoh*oe);
						tny+=m->gappov*oe;
						tnx = tnx + (m->gappih*ie/2);
						tnh/=2;
						tnh = tnh - (m->gappiv*ie/2) - (m->gappov*oe);
					} else if((i % 5) == 1) { //down
						tnx = tnx + (m->gappih*ie/2);
						tnw = tnw - (m->gappih*ie/2) - (m->gappoh*oe);
						tnh/=2;
						tnh = tnh - (m->gappiv*ie/2) - (m->gappov*oe);
						tny += nh/2;
						tny = tny + (m->gappiv*ie/2);
					}
					break;
				case 3://bottom, up-left and up-right
					if((i % 5) == 0) { //up-left
						tnx = tnx + (m->gappih*ie/2);
						tnw = nw/2;
						tnw = tnw - (m->gappih*ie/2) - (m->gappoh*oe/2);
						tny+=m->gappov*oe;
						tnh = (2*nh)/3;
						tnh = tnh - (m->gappiv*ie/2) - (m->gappov*oe);
					} else if((i % 5) == 1) { //up-right
						tny+=m->gappov*oe;
						tnx += nw/2;
						tnx = tnx + (m->gappih*ie) - (m->gappoh*oe/2);
						tnw = nw/2;
						tnw = tnw - (m->gappih*ie) - (m->gappoh*oe/2);
						tnh = (2*nh)/3;
						tnh = tnh - (m->gappiv*ie/2) - (m->gappov*oe);
					} else if((i % 5) == 2) { //bottom
						tnx = tnx + (m->gappih*ie/2);
						tnw = tnw - (m->gappih*ie/2) - (m->gappoh*oe);
						tnh = nh/3;
						tnh = tnh - (m->gappiv*ie/2) - (m->gappov*oe);
						tny += (2*nh)/3;	
						tny = tny + (m->gappiv*ie/2);
					}
					break;
				case 4://bottom, left, right and top
					if((i % 5) == 0) { //top
						tnx = tnx + (m->gappih*ie/2);
						tnw = tnw - (m->gappih*ie/2) - (m->gappoh*oe);
						tny = tny + (m->gappov*oe);
						tnh = (nh)/4;
						tnh = tnh - (m->gappiv*ie/2) - (m->gappov*oe/2);
					} else if((i % 5) == 1) { //left
						tnx = tnx + (m->gappih*ie/2);
						tnw = nw/2;
						tnw = tnw - (m->gappih*ie/2) - (m->gappoh*oe/2);
						tny += nh/4;
						tny = tny + (m->gappiv*ie/2) + (m->gappov*oe/2);
						tnh = (nh)/2;
						tnh = tnh - (m->gappiv*ie) - (m->gappov*oe);
					}
					else if((i % 5) == 2) { //right
						tnx += nw/2;
						tnx = tnx + (m->gappih*ie) - (m->gappoh*oe/2);
						tnw = nw/2;
						tnw = tnw - (m->gappih*ie) - (m->gappoh*oe/2);
						tny += nh/4;
						tny = tny + (m->gappiv*ie/2) + (m->gappov*oe/2);
						tnh = (nh)/2;
						tnh = tnh - (m->gappiv*ie) - (m->gappov*oe);
					} else if((i % 5) == 3) { //bottom
						tnx = tnx + (m->gappih*ie/2);
						tnw = tnw - (m->gappih*ie/2) - (m->gappoh*oe);
						tny += (3*nh)/4;
						tny = tny + (m->gappiv*ie/2) - (m->gappov*oe/2);
						tnh = (nh)/4;
						tnh = tnh - (m->gappiv*ie/2) - (m->gappov*oe/2);
					}
					break;
			}
			++i;
			resize(c, tnx, tny, tnw - (2 * bw), tnh - (2 * bw), bw, False);
		}
	
		++mats;
	
		for(i = 0; c && (mats>0); c = nexttiled(c->next)) {

			if((i%5)==0) {
				--mats;
				if(((tc % 5) > 0)||(i>=5)) {
					ny= ny + nh + (m->gappiv*ie) - (m->gappov*oe) - (m->gappiv*oe) - (m->gappiv*oe);
					nh = nh - (m->gappiv*ie) + (m->gappov*oe) + (m->gappiv*oe);
				}
			}
			
			tnw=nw;
			tnx=nx;
			tnh=nh;
			tny=ny;
			

			switch(i % 5) {
				case 0: //top-left-vert
					tnx = tnx + (m->gappih*ie/2);
					tny+=m->gappov*oe;
					tnw = (nw)/3;
					tnw = tnw - (m->gappih*ie/2) - (m->gappoh*oe/2);
					tnh = (nh*2)/3;
					tnh = tnh - (m->gappiv*ie/2) - (m->gappov*oe);
					tnh = tnh - (m->gappov*oe/2);
					break;
				case 1: //top-right-hor
					tny+=m->gappov*oe;
					tnx += (nw)/3;
					tnx = tnx + (m->gappih*ie) - (m->gappoh*oe/2);
					tnw = (nw*2)/3;
					tnw = tnw - (m->gappih*ie) - (m->gappoh*oe/2);
					tnh = (nh)/3;
					tnh = tnh - (m->gappiv*ie/2) - (m->gappov*oe/2);
					break;
				case 2: //center
					tnx += (nw)/3;
					tnx = tnx + (m->gappih*ie) - (m->gappoh*oe/2);
					tnw = (nw)/3;
					tnw = tnw - (m->gappih*ie) - (m->gappoh*oe/2);
					tny += (nh)/3;
					tny = tny + (m->gappiv*ie/2) + (m->gappov*oe/2);
					tnh = (nh)/3;
					tnh = tnh - (m->gappiv*ie) - (m->gappov*oe);
					break;
				case 3: //bottom-right-vert
					tnx += (nw*2)/3;
					tnx = tnx + (m->gappih*ie) - (m->gappoh*oe);
					tnw = (nw)/3;
					tnw = tnw - (m->gappih*ie);
					tny += (nh)/3;
					tny = tny + (m->gappiv*ie/2) + (m->gappov*oe/2);
					tnh = (nh*2)/3;
					tnh = tnh - (m->gappiv*ie/2) - (m->gappov*oe);
					tnh = tnh - (m->gappov*oe/2) + 1;
					break;
				case 4: //(oldest) bottom-left-hor
					tnx = tnx + (m->gappih*ie/2);
					tnw = (2*nw)/3;
					tnw = tnw - (m->gappih*ie/2) - (m->gappoh*oe);
					tny += (2*nh)/3;
					tny = tny + (m->gappiv*ie/2) - (m->gappov*oe/2);
					tnh = (nh)/3;
					tnh = tnh - (m->gappiv*ie/2) - (m->gappov*oe/2) + 1;
					break;
				default:
					break;
			}
			
			++i;
			//i%=5;
			resize(c, tnx, tny, tnw - (2 * bw), tnh - (2 * bw), bw, False);
		}
	}
}
