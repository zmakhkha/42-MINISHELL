# to replace in header
'''
static void *_malloc(size_t c, char *file, int line)
{
	void *p = malloc(c);
	printf("MALC: %p, LINE = %i, FILE = %s\n", p, line, file);
	return (p);
}

static void _free(void* c, char *file, int line)
{
	printf("FREE: %p, LINE = %i, FILE = %s\n", c, line, file);
	return (free(c));
}
'''

allocated = {}
freed = {}
hada = 'khawi'
# Read input from a file
filename = 'leaks.txt'
with open(filename, 'r') as file:
    file_content = file.read()

for line in file_content.split('\n'):
    line = line.strip()
    if not line:
        continue
    if not (line.startswith("FREE")  or line.startswith("MALC") or line.startswith("HADA")):
        continue
    pointer = line.split(' ')[1][:-1]
    _type = line.split(' ')[0][:-1]

    if _type == "FREE":
        freed[pointer] = 1
    if _type == "MALC":
        allocated[pointer] = line
    if _type == "HADA":
       hada = pointer

for key in freed:
    if key in allocated:
        allocated[key] = 0
print("working on hada " + hada)
print("-----------------------")
for key, value in allocated.items():
    if value != 0:
        print(value)
    if (hada == key):
        print("<--------------------------------->")
        print("hada a3ami :" + hada)
        print("<--------------------------------->")