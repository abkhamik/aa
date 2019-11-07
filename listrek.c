/*
Nama  : Muhammad Rizki Fonna
NIM   : 13516001
Kelas : 01
*/

#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"

/* *** Manajemen Memori *** */
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P,
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;
    P=(address) malloc(sizeof(infotype));
    if (P==Nil)
    {

    }
    else
    {
        Info(P)=X;
        Next(P)=Nil;
    }
    return (P);
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L)
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
{
    if (L!=Nil)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int IsOneElmt(List L)
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
{
    if (IsEmpty(L))
    {
        return 0;
    }
    else
    {
        return (Next(L)==Nil);
    }
}

/* *** Selektor *** */
infotype FirstElmt (List L)
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
{
    return (Info(L));
}
List Tail(List L)
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
{
    return (Next(L));
}

/* *** Konstruktor *** */
List Konso(infotype e, List L)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya.
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
{
    address P;
    P=Alokasi(e);
    if (P!=Nil)
    {
        Next(P)=L;
        return (P);
    }
    else
    {
        return L;
    }

}
List KonsB(List L, infotype e)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */
{
    address P;
    P=Alokasi(e);
    if(P!=Nil)
    {
        if(IsEmpty(L))
        {
            return (P);
        }
        else
        {
            Next(L)=KonsB(Tail(L),e);
            return (L);
        }
    }
    else
    {
        return (L);
    }
}

/* *** Operasi Lain *** */
List Copy (List L)
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */
{
    if (!IsEmpty(L))
    {
        return (Konso(FirstElmt(L),Copy(Tail(L))));
    }
    else
    {
        return (Nil);
    }
}
void MCopy (List Lin, List *Lout)
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
{
    List c;
    c=Copy(Lin);
    *Lout=c;
}
List Concat (List L1, List L2)
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
{
    if(!IsEmpty(L1))
    {
        return (Konso(FirstElmt(L1),Concat(Tail(L1),L2)));
    }
    else
    {
        return (Copy(L2));
    }
}
void MConcat (List L1, List L2, List *LHsl)
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
{
    List temp;
    if (!IsEmpty(L1))
    {
        MConcat(Tail(L1),L2,&temp);
        *LHsl=Konso(FirstElmt(L1),temp);
    }
    else
    {
        *LHsl=Copy(L2);
    }

}
void PrintList (List L)
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
{
    if (IsEmpty(L))
    {

    }
    else
    {
        printf("%d\n", FirstElmt(L));
        PrintList(Tail(L));
    }
}
int NbElmtList (List L)
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
{
    if(!IsEmpty(L))
    {
        return (1+NbElmtList(Tail(L)));
    }
    else
    {
        return 0;
    }

}
boolean Search (List L, infotype X)
/* Mengirim true jika X adalah anggota list, false jika tidak */
{
    if (!IsEmpty(L))
    {
        if (FirstElmt(L) == X)
        {
            return (true);
        }
        else
        {
            return (Search(Tail(L), X));
        }
    }
    else
    {
        return (false);
    }

}

void MinMax(List L, int *Min, int *Max)
{
	if (IsEmpty(L))
	{
		//printf("IsEmpty(L)");
		*Max=-9999;
		*Min=9999;
		
	}
	else
	{
		//printf("notIsEmpty\n");
		MinMax(Tail(L), Min, Max);
		if (Info(L)>(*Max))
		{
			*Max=Info(L);
			
		}
		if (Info(L)<(*Min))
		{
			*Min=Info(L);
			
		}
		//printf("%d", *Max);
		
	}
	
}


infotype SumList (List L)
/* Mengirimkan total jumlah elemen List L */
{
	if (IsEmpty(L))
	{
		return 0;
		
		
	}
	else
	{
		return (FirstElmt(L)+SumList(Tail(L)));
		
		
		
	}
	
}

int ListCompare(List L1, List L2)
{
	if ((IsEmpty(L1))&&(IsEmpty(L2)))
	{
		//printf("((IsEmpty(L1))&&(IsEmpty(L2)))\n");
		return 0;
		
	}
	else if (((IsEmpty(L1))&&(!IsEmpty(L2))))
	{
		//printf("(((IsEmpty(L1))&&(!IsEmpty(L2))))\n");
		return -1;
		
	}
	else if (((!IsEmpty(L1))&&(IsEmpty(L2))))
	{
		//printf("(((!IsEmpty(L1))&&(IsEmpty(L2))))\n");
		return 1;
		
	}
	else
	{
		//printf("else\n");
		if (FirstElmt(L1)==FirstElmt(L2))
		{
			ListCompare(Tail(L1), Tail(L2));
			
		}
		else
		{
			if (FirstElmt(L1)>FirstElmt(L2))
			{
				return 1;
				
			}
			else
			{
				return -1;
				
			}
			
			
		}
		
		
		
		
	}
	
	
	
	
}



float AverageList (List L)
/* Mengirimkan nilai rata-rata elemen list L */
{
	return ((float) SumList(L)/NbElmtList(L));
	
}


void SplitOnX(List L, infotype X, List *L1, List *L2)
{
	if (IsEmpty(L))
	{
		//printf("IsEmpty(L)\n");
		
	}
	else
	{
		//printf("else\n");
		
		if (FirstElmt(L)<X)
		{
			*L1=KonsB(*L1, FirstElmt(L));
			//printf("L1 :\n");
			//PrintList(*L1);
			//printf("\n");
			
		}
		else
		{
			*L2=KonsB(*L2, FirstElmt(L));
			//printf("L2 :\n");
			//PrintList(*L2);
			//printf("\n");
			
		}
		SplitOnX(Tail(L), X, L1, L2);
		
		
	}
	
	
	
	
	
	
}


List InverseList (List L)  //belum beres
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
{
	if (IsEmpty(L))
	{
		List L2=Nil;
		return L2;
		
	}
	else
	{
		List L3=Nil;
		L3=KonsB(InverseList(Tail(L)), FirstElmt(L));
		//infotype el;
		//el=FirstElmt(L);
		//address P=Alokasi(el);
		//return Konso(
		
		
	}
	
	
	
	
	
}

boolean IsAllExist(List L1, List L2)  //masih belum beres
{
	if ((IsEmpty(L1))&&(!IsEmpty(L2)))
	{
		//printf("((IsEmpty(L1))&&(!IsEmpty(L2)))\n");
		return true;
		
	}
	else if ((!IsEmpty(L1))&&(IsEmpty(L2)))
	{
		//printf("((!IsEmpty(L1))&&(IsEmpty(L2)))\n");
		return false;
	}
	else if ((IsEmpty(L1))&&(IsEmpty(L2)))
	{
		//printf("((IsEmpty(L1))&&(IsEmpty(L2)))\n");
		return true;
		
	}
	else
	{
		//printf("else\n");
		if (Search(L2, FirstElmt(L1)))
		{
			//printf("(Search(L2, FirstElmt(L1)))\n");
			//printf("%d\n", FirstElmt(L1));
			IsAllExist(Tail(L1), L2);
			
		}
		else
		{
			//printf("bukan(Search(L2, FirstElmt(L1)))\n");
			return false;
		}
	}
	
}

void SplitPosNeg (List L, List *L1, List *L2)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */ 
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */
{
	if (IsEmpty(L))
	{
		
		
	}
	else
	{
		if (FirstElmt(L)>=0)
		{
			*L1=KonsB(*L1, FirstElmt(L));
			SplitPosNeg(Tail(L), L1, L2);
			
		}
		else
		{
			*L2=KonsB(*L2, FirstElmt(L));
			SplitPosNeg(Tail(L), L1, L2);
			
			
		}
		
	}
	
	
	
	
	
	
}






