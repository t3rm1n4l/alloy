#include "LLVM/LLVMcodegen.h"

// Declarations

/**
 * Jumps ahead in the AST we're parsing
 * @param self   the code gen instance
 * @param amount the amount to consume by
 */
static void consumeAstNodeBy(LLVMCodeGenerator *self, int amount);

/**
 * Run through all the nodes in the AST and
 * generate the code for them!
 * @param self the code gen instance
 */
static void traverseAST(LLVMCodeGenerator *self);

// Definitions

LLVMCodeGenerator *createLLVMCodeGenerator(Vector *sourceFiles) {
	LLVMCodeGenerator *self = safeMalloc(sizeof(*self));
	self->abstractSyntaxTree = NULL;
	self->currentNode = 0;
	self->sourceFiles = sourceFiles;
	return self;
}

static void consumeAstNode(LLVMCodeGenerator *self) {
	self->currentNode += 1;
}

static void consumeAstNodeBy(LLVMCodeGenerator *self, int amount) {
	self->currentNode += amount;
}

void startLLVMCodeGeneration(LLVMCodeGenerator *self) {
	/*HeaderFile *boilerplate = createHeaderFile("_alloyc_boilerplate");
	writeHeaderFile(boilerplate);
	fprintf(boilerplate->outputFile, "%s", BOILERPLATE);
	closeHeaderFile(boilerplate);
	
	for (int i = 0; i < self->sourceFiles->size; i++) {
		SourceFile *sf = getVectorItem(self->sourceFiles, i);
		self->currentNode = 0;
		self->currentSourceFile = sf;
		self->abstractSyntaxTree = self->currentSourceFile->ast;
		
		writeFiles(self->currentSourceFile);

		self->writeState = WRITE_SOURCE_STATE;
		// _gen_name.h is the typical name for the headers and c files that are generated
		emitCode(self, "#include \"_gen_%s.h\"\n", self->currentSourceFile->name);

		// write to header
		self->writeState = WRITE_HEADER_STATE;
		emitCode(self, "#ifndef __%s_H\n", self->currentSourceFile->name);
		emitCode(self, "#define __%s_H\n\n", self->currentSourceFile->name);

		generateMacrosC(self);

		emitCode(self, "#include \"%s\"\n", boilerplate->generatedHeaderName);

		// compile code
		traverseAST(self);

		// write to header
		self->writeState = WRITE_HEADER_STATE;
		emitCode(self, "\n");
		emitCode(self, "#endif // __%s_H\n", self->currentSourceFile->name);

		// close files
		closeFiles(self->currentSourceFile);
	}
	
	// empty command
	sds buildCommand = sdsempty();

	// what compiler to use
	buildCommand = sdscat(buildCommand, COMPILER);
	buildCommand = sdscat(buildCommand, " ");
	
	// additional compiler flags, i.e -g, -Wall etc
	buildCommand = sdscat(buildCommand, ADDITIONAL_COMPILER_ARGS);

	// output name
	buildCommand = sdscat(buildCommand, " -o ");
	buildCommand = sdscat(buildCommand, OUTPUT_EXECUTABLE_NAME);

	// files to compile	
	buildCommand = sdscat(buildCommand, " ");
	// append the filename to the build string
	for (int i = 0; i < self->sourceFiles->size; i++) {
		SourceFile *sourceFile = getVectorItem(self->sourceFiles, i);
		buildCommand = sdscat(buildCommand, sourceFile->generatedSourceName);

		if (i != self->sourceFiles->size - 1) // stop whitespace at the end!
			buildCommand = sdscat(buildCommand, " ");
	}

	// linker options
	buildCommand = sdscat(buildCommand, " ");
	buildCommand = sdscat(buildCommand, self->linkerFlags);

	// just for debug purposes
	verboseModeMessage("Running cl args: `%s`", buildCommand);

	// do the command we just created
	int result = system(buildCommand);
	if (result != 0)
		exit(2);
	
	sdsfree(self->linkerFlags);
	sdsfree(buildCommand); // deallocate dat shit baby
	
	destroyHeaderFile(boilerplate);*/
}

void destroyLLVMCodeGenerator(LLVMCodeGenerator *self) {
	/*for (int i = 0; i < self->sourceFiles->size; i++) {
		SourceFile *sourceFile = getVectorItem(self->sourceFiles, i);
		destroySourceFile(sourceFile);
		verboseModeMessage("Destroyed source files iteration %d", i);
	}

	free(self);
	verboseModeMessage("Destroyed compiler");*/
}
