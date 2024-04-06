Skip to content
Product
Solutions
Open Source
Pricing
Search
Sign in
Sign up
orcnyilmaz
/
Samosa-Bhai-Problem
Public
Code
Issues
Pull requests
Actions
Projects
Security
Insights
Samosa Bhai Problem Solution
 master
Orçun Yılmaz authored and Orçun Yılmaz committed on Jun 26, 2016 
0 parents commit 37e70e5a39bb7c0cf3c0d57646316c21b60ed8de
Show file tree Hide file tree
Showing 6 changed files with 85 additions and 0 deletions.
Filter changed files
 6  
.classpath
@@ -0,0 +1,6 @@
<?xml version="1.0" encoding="UTF-8"?>
<classpath>
	<classpathentry kind="src" path="src"/>
	<classpathentry kind="con" path="org.eclipse.jdt.launching.JRE_CONTAINER/org.eclipse.jdt.internal.debug.ui.launcher.StandardVMType/JavaSE-1.8"/>
	<classpathentry kind="output" path="bin"/>
</classpath>
 17  
.project
@@ -0,0 +1,17 @@
<?xml version="1.0" encoding="UTF-8"?>
<projectDescription>
	<name>SamosaBhai</name>
	<comment></comment>
	<projects>
	</projects>
	<buildSpec>
		<buildCommand>
			<name>org.eclipse.jdt.core.javabuilder</name>
			<arguments>
			</arguments>
		</buildCommand>
	</buildSpec>
	<natures>
		<nature>org.eclipse.jdt.core.javanature</nature>
	</natures>
</projectDescription>
 11  
.settings/org.eclipse.jdt.core.prefs
@@ -0,0 +1,11 @@
eclipse.preferences.version=1
org.eclipse.jdt.core.compiler.codegen.inlineJsrBytecode=enabled
org.eclipse.jdt.core.compiler.codegen.targetPlatform=1.8
org.eclipse.jdt.core.compiler.codegen.unusedLocal=preserve
org.eclipse.jdt.core.compiler.compliance=1.8
org.eclipse.jdt.core.compiler.debug.lineNumber=generate
org.eclipse.jdt.core.compiler.debug.localVariable=generate
org.eclipse.jdt.core.compiler.debug.sourceFile=generate
org.eclipse.jdt.core.compiler.problem.assertIdentifier=error
org.eclipse.jdt.core.compiler.problem.enumIdentifier=error
org.eclipse.jdt.core.compiler.source=1.8
 BIN +1.9 KB 
bin/SamosaBhai.class
Binary file not shown.
 0  
gitinit
Empty file.
 51  
src/SamosaBhai.java
@@ -0,0 +1,51 @@
import java.util.ArrayList;
import java.util.Scanner;

public class SamosaBhai {

	public SamosaBhai() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scanner = new Scanner(System.in);
		int testCaseNumbers = scanner.nextInt();
		double numberOfHouses, exponent, firstHouse, nextHouse, beforeHouse, tempVal1, tempVal2, result;
		ArrayList<Integer> tempArrList = new ArrayList<Integer>();

		while (testCaseNumbers > 0)	{
			result = 0;
			tempArrList.clear();
			numberOfHouses = scanner.nextInt();
			exponent = scanner.nextInt();
			for(int iterator = 0; iterator < numberOfHouses; iterator++) {
				tempArrList.add(scanner.nextInt());
			}

			for(int it = 0; it < tempArrList.size(); it++) {
				firstHouse = tempArrList.get(it);
				for(int iter = (it + 1); iter < tempArrList.size(); iter++) {
					nextHouse = tempArrList.get(iter);
					tempVal1 = Math.abs(firstHouse - nextHouse);
					result = result + Math.pow(tempVal1, exponent);
				}

				for(int iter2 = it; iter2 > 0; iter2--) {
					if (iter2 == 0)
						break;
					beforeHouse = tempArrList.get(iter2 - 1);
					tempVal2 = Math.abs(firstHouse - beforeHouse);
					result = result + Math.pow(tempVal2, exponent);
				}
			}

			System.out.println(result);

			testCaseNumbers--;
		}

	}

}
0 comments on commit 37e70e5
Please sign in to comment.
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
Samosa Bhai Problem Solution · orcnyilmaz/Samosa-Bhai-Problem@37e70e5 · GitHub