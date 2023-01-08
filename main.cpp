#include <iostream>
#include <vector>
#include <field.h>
#include <image_generator.h>
#include <bmp_writer.h>



struct Args {
    unsigned int width;
    unsigned int height;
    unsigned int cols;
    unsigned int rows;

    bool with_seed;
    unsigned int seed;

    std::string filepath;
};

static unsigned int
parseUInt(char* arg)
{
    char *end;
    return strtoul(arg, &end, 10);
}

static struct Args
parseArgs(int argc, char** argv)
{
    if (argc < 7)
        throw std::invalid_argument("Number of args less than 6: width, height, " \
                                    "columns, rows, seed, output file");

    Args ret;
    char *end;

    ret.width = parseUInt(argv[1]);
    ret.height = parseUInt(argv[2]);
    ret.cols = parseUInt(argv[3]);
    ret.rows = parseUInt(argv[4]);
    ret.seed = parseUInt(argv[5]);
    ret.filepath = std::string(argv[6]);

    return ret;
}

int
main(int argc, char** argv)
{
    Args args;

    try {
        args = parseArgs(argc, argv);
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return -1;
    }

    Field f = Field::createEmptyField(args.cols, args.rows);
    ImageGenerator ig(args.width, args.height);
    ig.addBorders(f);

    BmpWriter bw(args.filepath, ig);
    bw.writeFile();

    return 0;
}
