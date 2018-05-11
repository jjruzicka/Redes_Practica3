#include "Serializable.h"

#include <iostream>
#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

class Jugador: public Serializable
{
public:
    Jugador(const char * _n, int16_t _x, int16_t _y):x(_x),y(_y)
    {
        strncpy(name, _n, 80);
    };

    virtual ~Jugador(){};

    void to_bin()
    {
	int32_t total = 80 * sizeof(char) + 2 * sizeof(int16_t);
	alloc_data(total);
	char * tmp = data + sizeof(int32_t);
	memcpy(tmp, name, 80); // name
	tmp += 80;
	memcpy(tmp, &x, sizeof(int16_t)); //x
	tmp += sizeof(int16_t);
	memcpy(tmp, &y, sizeof(int16_t)); //y
	tmp += sizeof(int16_t);
    }

    int from_bin(char * data)
    {
	char * tmp = data * sizeof(int23_t);
	memcpy (name, tmp, 80);
	tmp += 80;
	memcpy(&x, tmp, int16_t);
	tmp += sizeof(int16_t);
	memcpy(&y, tmp, int16_t);
	
    }

private:
    char name[MAX_NAME];

    int16_t x;
    int16_t y;

    static const size_t MAX_NAME = 20;

};

int main(int argc, char **argv)
{
	Jugador one("Player one", 12, 345);

	const char * path = "./ejercicio1.txt"	
	open(path, O_RDWR/*lectura y escritura*/);
	
	

}
