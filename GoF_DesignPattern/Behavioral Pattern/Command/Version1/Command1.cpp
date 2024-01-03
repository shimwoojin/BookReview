#include "Command1.h"
#include <cassert>
#include <filesystem>
#include <iostream>

void OpenCommand::Execute()
{
	file_stream->open(file_name, std::ios::out | std::ios::app);
	
	if (file_stream->fail())
	{
		assert(false && "Fail File Openning!!");
	}
}

void WriteCommand::Execute()
{
	if (comment.empty() == false && file_stream->is_open())
	{
		file_stream->write(comment.c_str(), comment.size());
		comment.clear();
	}
}

void WriteCommand::SetComment(std::string comment)
{
	this->comment = comment;
}

void CloseCommand::Execute()
{
	file_stream->close();
}
