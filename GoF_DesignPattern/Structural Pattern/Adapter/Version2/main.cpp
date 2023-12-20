#include "Adapter2.h"

int main()
{
	ToiletTissue_V2 t_tissue1;
	ToiletTissue_V2 t_tissue2;
	Destructible_V2 destructible;
	SoftDestructible soft_destructible;

	t_tissue1.SetDestructible(&destructible);
	t_tissue2.SetDestructible(&soft_destructible);

	t_tissue1.Sop();
	t_tissue2.Sop();

	return 0;
}