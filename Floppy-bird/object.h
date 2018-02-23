class playerObject
{
public:
	double x = 200;
	double y = 200;
	int width = 30;
	int height = 30;
private:
};

class eObject
{
public:
	double x;
	double y;

	double xv = -3;
	double yv = 0;

	int width = 50;
	int height = 100;
	eObject();
	eObject(double f_x, double f_y)
		:x(f_x)
		,y(f_y)
	{}
private:
};
