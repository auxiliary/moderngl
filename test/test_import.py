import os; os.chdir(os.path.dirname(__file__))
import unittest, importlib

class TestImport(unittest.TestCase):

	def test_import(self):
		importlib.import_module('ModernGL')

if __name__ == '__main__':
	unittest.main()
