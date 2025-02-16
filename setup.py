from distutils.core import setup, Extension

def main():
    setup(name="hello",
          version="1.0.0",
          description="Python interface for print hello args function",
          author="myName",
          author_email="email",
          ext_modules=[Extension("hello", ["helloModule.c"])])

if __name__ == "__main__":
    main()

