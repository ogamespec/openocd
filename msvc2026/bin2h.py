#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import argparse
import os
import sys

def bin2h(input_file, output_file, array_name, chunk_size=16, use_stdout=False):
    """
    Преобразует бинарный файл в C-заголовок с массивом байтов.
    
    Args:
        input_file: Входной бинарный файл
        output_file: Выходной .h файл
        array_name: Имя массива в C-коде
        chunk_size: Количество байтов на строку
        use_stdout: Вывод в stdout вместо файла
    """
    try:
        # Читаем бинарный файл
        with open(input_file, 'rb') as f:
            data = f.read()
        
        # Создаем содержимое .h файла
        lines = []
        lines.append(f'/* Автоматически сгенерировано из {os.path.basename(input_file)} */')
        lines.append(f'/* Размер: {len(data)} байт */')
        lines.append('#pragma once\n')
        lines.append('#include <stdint.h>\n')
        lines.append(f'const uint8_t {array_name}[] = {{')
        
        # Формируем массив байтов
        for i in range(0, len(data), chunk_size):
            chunk = data[i:i + chunk_size]
            hex_bytes = ', '.join(f'0x{byte:02x}' for byte in chunk)
            lines.append(f'    {hex_bytes},')
        
        lines.append(f'}};')
        lines.append(f'const uint32_t {array_name}_size = sizeof({array_name});')
        
        # Объединяем все строки
        content = '\n'.join(lines)
        
        # Выводим результат
        if use_stdout:
            print(content)
        else:
            with open(output_file, 'w', encoding='utf-8') as f:
                f.write(content)
            
            print(f'Файл {output_file} успешно создан')
            print(f'Размер данных: {len(data)} байт')
            print(f'Имя массива: {array_name}')
        
    except FileNotFoundError:
        print(f'Ошибка: файл {input_file} не найден', file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print(f'Ошибка: {e}', file=sys.stderr)
        sys.exit(1)

def main():
    parser = argparse.ArgumentParser(
        description='Преобразование бинарного файла в C-заголовок (bin2h)',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Примеры использования:
  %(prog)s firmware.bin -o firmware.h -n firmware_data
  %(prog)s image.png -n my_image --stdout
  %(prog)s data.bin -n embedded_data -c 32
        """
    )
    
    parser.add_argument('input', help='Входной бинарный файл')
    parser.add_argument('-o', '--output', help='Выходной .h файл (если не указан, будет использовано имя входного файла с расширением .h)')
    parser.add_argument('-n', '--name', default='binary_data', 
                       help='Имя массива в C-коде (по умолчанию: binary_data)')
    parser.add_argument('-c', '--chunk', type=int, default=16,
                       help='Количество байтов на строку (по умолчанию: 16)')
    parser.add_argument('--stdout', action='store_true',
                       help='Вывести результат в стандартный вывод вместо файла')
    
    args = parser.parse_args()
    
    # Если выходной файл не указан, генерируем его имя
    if not args.stdout and not args.output:
        base_name = os.path.splitext(os.path.basename(args.input))[0]
        args.output = base_name + '.h'
    
    # Вызываем функцию преобразования
    bin2h(
        input_file=args.input,
        output_file=args.output if not args.stdout else None,
        array_name=args.name,
        chunk_size=args.chunk,
        use_stdout=args.stdout
    )

if __name__ == '__main__':
    main()