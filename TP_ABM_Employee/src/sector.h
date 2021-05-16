#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct{
    int id;
    char description[20];
}Sector;

int cargarDescripcionSector(int id, Sector sectors[], int secLen, char descrip[]);
int printSectors(Sector sectors[], int secLen);
void printSector(Sector sec);

#endif // SECTOR_H_INCLUDED
