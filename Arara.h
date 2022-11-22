#include "Inimigo.h"

namespace Entidades
{

    namespace Personagens

    {

        class Arara: public Inimigo
        {
            private:
                int aumentaVel;

            public:
                Arara(Jogador *j, float x, float y);
                ~Arara();
                void ataque();
                void viradoEsq();
                void viradoDir();
                void ataqueDir();
                void ataqueEsq();
                void calculaAvanco();

        };

    }

}