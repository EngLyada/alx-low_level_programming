#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_idt);
void print_magic(unsigned char *e_idt);
void print_class(unsigned char *e_idt);
void print_data(unsigned char *e_idt);
void print_version(unsigned char *e_idt);
void print_abi(unsigned char *e_idt);
void print_osabi(unsigned char *e_idt);
void print_type(unsigned int e_t, unsigned char *e_idt);
void print_entry(unsigned long int e_e, unsigned char *e_idt);
void close_elf(int eld);

/**
 * check_elf - ELF file checking method.
 * @e_idt: A pointer to ELF magic numbers array.
 */
void check_elf(unsigned char *e_idt)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_idt[i] != 127 &&
		    e_idt[i] != 'E' &&
		    e_idt[i] != 'L' &&
		    e_idt[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic -ELF header magic number printing.
 * @e_idt: A pointer to ELF magic numbers array
 *
 */
void print_magic(unsigned char *e_idt)
{
	int i;

	printf(" Magic: ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_idt[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - ELF header Class printing method.
 * @e_idt: A pointer to ELF Class array
 */
void print_class(unsigned char *e_idt)
{
	printf(" Class: ");

	switch (e_idt[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idt[EI_CLASS]);
	}
}

/**
 * print_data - ELF header data printing method.
 * @e_idt: A pointer to ELF data array
 */
void print_data(unsigned char *e_idt)
{
	printf(" Data: ");

	switch (e_idt[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idt[EI_CLASS]);
	}
}

/**
 *  * print_version - ELF header Version printing method.
 *   * @e_idt: ELF version array pointer.
 *    */
void print_version(unsigned char *e_idt)
{
	 printf(" Version: %d",
			  e_idt[EI_VERSION]);

	switch (e_idt[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - ELF header v printing method.
 * @e_idt: ELF version array pointer.
 */
void print_osabi(unsigned char *e_idt)
{
	printf(" OS/ABI: ");

	switch (e_idt[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idt[EI_OSABI]);
	}
}

/**
 * print_abi - ELF header ABI version printing method.
 * @e_idt: ELF ABI version array pointer.
 */
void print_abi(unsigned char *e_idt)
{
	printf(" ABI Version: %d\n",
		e_idt[EI_ABIVERSION]);
}

/**
 * print_type - ELF header type printing method.
 * @e_t: The ELF type.
 * @e_idt: ELF class array pointer.
 */
void print_type(unsigned int e_t, unsigned char *e_idt)
{
	if (e_idt[EI_DATA] == ELFDATA2MSB)
		e_t >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_t);
	}
}

/**
 * print_entry - ELF header entry point printing.
 * @e_e: ELF entry point address.
 * @e_idt: ELF class array pointer.
 */
void print_entry(unsigned long int e_e, unsigned char *e_idt)
{
	printf(" Entry point address: ");

	if (e_idt[EI_DATA] == ELFDATA2MSB)
	{
		e_e = ((e_e << 8) & 0xFF00FF00) |
			  ((e_e >> 8) & 0xFF00FF);
		e_e = (e_e << 16) | (e_e >> 16);
	}

	if (e_idt[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_e);

	else
		printf("%#lx\n", e_e);
}

/**
 * close_elf - ELF file closing method.
 * @eld: ELF file descriptor.
 *
 */
void close_elf(int eld)
{
	if (close(eld) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", eld);
		exit(98);
	}
}

/**
 * main – Displaying info in ELF header at the start
 * @ac: Argument number in the program.
 * @av: Arguments pointer array.
 *
 * Return: 0 on success.
 *
 */
int main(int __attribute__((__unused__)) ac, char *av[])
{
	Elf64_Ehdr *hd;
	int on, rd;

	on = open(av[1], O_RDONLY);
	if (on == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	hd = malloc(sizeof(Elf64_Ehdr));
	if (hd == NULL)
	{
		close_elf(on);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	rd = read(on, hd, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(hd);
		close_elf(on);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", av[1]);
		exit(98);
	}

	check_elf(hd->e_idt);
	printf("ELF Header:\n");
	print_magic(hd->e_idt);
	print_class(hd->e_idt);
	print_data(hd->e_idt);
	print_version(hd->e_idt);
	print_osabi(hd->e_idt);
	print_abi(hd->e_idt);
	print_type(hd->e_t, hd->e_idt);
	print_entry(hd->e_e, hd->e_idt);

	free(hd);
	close_elf(on);
	return (0);
}
