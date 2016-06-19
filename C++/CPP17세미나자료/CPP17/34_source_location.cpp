// 34_source_location

// __LINE__, __FILE__ extension

int main()
{
	source_location s = source_location::current();

	cout << s.file_name() << endl;
	cout << s.line() << endl;
	cout << s.column() << endl;
	cout << s.function_name() << endl;
}