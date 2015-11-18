enum comands
{
	cmd_Push = 1,
	cmd_Pop = 2,
	cmd_Add = 3,
	cmd_Sub = 4,
	cmd_Mul = 5,
	cmd_Div = 6
};

#define NumberFunction (sizeof(Mass))/(sizeof(struct Cmd))

struct Cmd
{
	int num;
	const char*name;
	int arg;
};

const struct Cmd Mass[] = 
{
	{cmd_Push, "PUSH", 1},
	{cmd_Pop, "POP", 0},
	{cmd_Add, "ADD", 0},
	{cmd_Sub, "SUB", 0},
	{cmd_Mul, "MUL", 0},
	{cmd_Div, "DIV", 0}
};
