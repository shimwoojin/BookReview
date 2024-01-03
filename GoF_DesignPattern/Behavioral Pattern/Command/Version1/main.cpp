#include "Command1.h"
#include <fstream>

int main()
{
	std::fstream file_stream;

	OpenCommand open_command(&file_stream, "HelloWorld");
	WriteCommand write_command(&file_stream);
	CloseCommand close_command(&file_stream);

	open_command.Execute();

	write_command.SetComment("HelloWorld!!");
	write_command.Execute();

	close_command.Execute();

	return 0;
}