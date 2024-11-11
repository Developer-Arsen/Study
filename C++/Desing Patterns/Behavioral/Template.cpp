#include <iostream>

class IDocumentProcessor {
    public:
        void processDocument () {
            openDocument();
            convertDocument();
            saveDocument();
            closeDocument();
        }
    protected:
        void openDocument() {
            std::cout << "Opening the document..." << std::endl;
        }

        virtual void  convertDocument() = 0;
        virtual void  saveDocument() = 0;

        void closeDocument() {
            std::cout << "Document is closed..." << std::endl;
        }
};

class PDFProcessor : public IDocumentProcessor {
    protected:
    void convertDocument() override {
        std::cout << "Converting document to PDF format..." << std::endl;
    }

    void saveDocument() override {
        std::cout << "Saving document as a .pdf file" << std::endl;
    }
};

class WordProcessor : public IDocumentProcessor {
protected:
    void convertDocument() override {
        std::cout << "Converting document to Word format..." << std::endl;
    }

    void saveDocument() override {
        std::cout << "Saving document as a .docx file" << std::endl;
    }
};

int main () {
    PDFProcessor pdfproccesor;
    pdfproccesor.processDocument();

    WordProcessor wordporcessor;
    wordporcessor.processDocument();
}
