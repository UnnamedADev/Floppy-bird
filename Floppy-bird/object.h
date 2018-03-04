class playerObject
{
public:
	double x = 200;
	double y = 200;
	int width = 30;
	int height = 30;
	int score = 0;

	void restart();
private:
};

class eObject
{
public:
	int width = 50;
	int upheight = 30;
	int downheight = 30;

	double x = 800;
	double y1 = 0;
	double y2 = 600;

	double xv = -3;
	double yv = 0;
	
	eObject(int f_upheight = 0, int f_downheight = 0) {
		this->upheight += f_upheight;
		this->downheight += f_downheight;
	};

private:
};
