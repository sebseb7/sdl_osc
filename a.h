
struct sdlosc_tabpage_t 
{
	char name[20];
	int active;
	void* first_item;
	void* next_tabpage;
};

enum {
	SDLOSC_MULTITOGGLE,
	SDLOSC_LABEL,
	SDLOSC_LED,
	SDLOSC_MULTIFADER,
	SDLOSC_XY,
	SDLOSC_ENCODER
};

struct sdlosc_control_t
{
	char name[20];
	int x;
	int y;
	int w;
	int h;
	int color;
	int type;
	void* control;
	void* next_item;
};

struct sdlosc_multitoggle_t
{
	float scalef;
	float scalet;
	int number_x;
	int number_y;
	int ex_mode;
	int local_off;
	int state;
};
struct sdlosc_label_t
{
	char text[20];
	int size;
	int orient;
	int background;
	int outline;
};
struct sdlosc_led_t
{
	float scalef;
	float scalet;
	int state;
};

struct sdlosc_multifader_t
{
	float scalef;
	float scalet;
	int inverted;
	int centered;
	int number;
	int orientation;
	int state[16];
};

struct sdlosc_xy_t
{
	int inverted_x;
	int inverted_y;
	float scalef;
	float scalet;
	int x;
	int y;
};

struct sdlosc_encoder_t
{
	float scalef;
	float scalet;
};


