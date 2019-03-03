#pragma once

class CommandLine
{
	int _argc;
	LPWSTR* _argv;
public:
	explicit CommandLine(LPCWSTR data)
	{
		_argv = CommandLineToArgvW(data, &_argc);
		if (!_argv) throw Win32Error(L"CommandLineToArgvW");
	}

	~CommandLine()
	{
		if (_argv) LocalFree(_argv);
	}

	int argc() const { return _argc; }
	int size() const { return _argc; }
	LPCWSTR argv(int n) { return _argv[n]; }
};
