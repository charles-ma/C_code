main() {
  parse_function_header("int fun0 () {");
  parse_function_header("int fun1 (int a) {");
  parse_function_header("int fun2 (int dog, int cat) {");
  parse_function_header("int fun3 (int larry, int moe, int curly) {");

  parse_line("int x;");
  parse_line("int j, k;");
  parse_line("int y = 2;");
  parse_line("int a = x + 5;");
  parse_line("int b = a + y + 8;");
  parse_line("int c = a + x, d, e = b;");


}
