program forLoop(input, output);

var
    nombre : string;

begin
    maxFilas := 3;
    maxColumnas := 7;

    for fila := 1 to maxFilas do
    begin
        for columna := 1 to maxColumnas do
            write("*");
        write("\n");
    end.
end.