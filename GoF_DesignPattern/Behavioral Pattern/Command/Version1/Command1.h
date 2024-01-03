#pragma once
#include <string>
#include <fstream>

__interface Command
{
	void Execute();
};

class OpenCommand : public Command
{
public:
	OpenCommand(std::fstream* file_stream, std::string file_name) : file_stream(file_stream), file_name(file_name) {}

	virtual void Execute() override;

private:
	std::string file_name;
	std::fstream* file_stream;
};

class WriteCommand : public Command
{
public:
	WriteCommand(std::fstream* file_stream) : file_stream(file_stream) {}

	virtual void Execute() override;
	void SetComment(std::string comment);

private:
	std::string comment;
	std::fstream* file_stream;
};

class CloseCommand : public Command
{
public:
	CloseCommand(std::fstream* file_stream) : file_stream(file_stream) {}

	virtual void Execute() override;

private:
	std::fstream* file_stream;
};