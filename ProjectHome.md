# Welcome to my beautiful research #
My name is Evance Soumaoro,
this place is where I store inovations, ideas, algorithm and code and I have found without using any guide or documentation. Note that these solutions might not be the efficient one but I like to keep them as remainder to say "if I was the first person to think about it, this is the way I would have done it on the first attempt".

browse the source to get more ...

# A Figure to Word Converter (French) #
I created this code a week after being introduce to Java programming language at UGANC.
fortunately I have never been a fan of java.
Why ?
-it's just too slow in my opinion.
-I dont mind developing project on it thought but I hate applications built on top of java:
> "NetBeans Could be the best IDE ever but it ..."

```
/*
Module: permet de convertir les chiffres en lettre
Auteur: Evance Soumaoro
Date: 25-Mai-2008
*/
public class conversion{
    static int t ;
    static boolean bol =false ;
    //=====================DEBUT MAIN======================DEBUT MAIN==================
    public static void main (String[] pour)
    {
        int m ;
        String lt1 ,lt2 ,lt3 ,lt4 ,chaine="",lnbre ;
        System.out.println("donnez le nombre à convertir");
        lnbre= lire();
        //affectation de la taiile de la chaine saisie par utilisateur
        m=lnbre.length() ;
        int[] args ;
        //tableau contenant dans une cellule un caractère extrait de la chaine
        args= new int[m] ;
        /* int */  t=args.length;
        if (m%3==0) //pour les indice 3,6,9 12
        {
            for (int i = 0; i&lt;m; i++)  {
                args[i]=Integer.parseInt(lnbre.charAt(i)+"");
            }
        }
        else
        {
            if(m%3==1)//pour les indice 1,4,7,10,
            {
                args= new int[m+2] ;
                //insertion dans les case non definie par utilisateur des val entières #tes de 1,..9
                args[0]=12;
                args[1]=12;
                for (int i = 2; i&lt;m+2; i++)
                {
                    //extraction et remplissage du tableau args
                    args[i]=Integer.parseInt(lnbre.charAt(i-2)+"");
                }
            }
            if (m%3==2)//pour les indice 2,5,8,11
            {
                args= new int[m+1] ;
                args[0]=12;
                for (int i = 1; i&lt;m+1; i++)
                {
                    args[i]=Integer.parseInt(lnbre.charAt(i-1)+"");
                }
            }
        }
        // appel des fonctions selon la taille originale du tableau (L_13)
        
        if (t&lt;=12 & t&gt;9)
        {
            //appel de convertrois avec tab de trois elem en paramètre
            lt1=convertrois(new int[]{args[0],args[1],args[2]});
            lt2=convertrois(new int[]{args[3],args[4],args[5]});
            lt3=convertrois(new int[]{args[6],args[7],args[8]});
            lt4=convertrois(new int[]{args[9],args[10],args[11]});
            if (lt2.length()!=0)
            {
                lt2=lt2+" millions ";
            }
            
            if (lt3.length()!=0)
            {
                lt3=lt3+" milles ";
            }
            chaine=lt1+" milliards "+" "+lt2+" "+lt3+" "+lt4;
            // ancien chaine=lt1+" milliards "+lt2+" millions "+lt3+" milles "+lt4;
            System.out.println(chaine)  ;
        }
        if (t&lt;=9 & t&gt;6)
        {
            lt1=convertrois(new int[]{args[0],args[1],args[2]});
            lt2=convertrois(new int[]{args[3],args[4],args[5]});
            lt3=convertrois(new int[]{args[6],args[7],args[8]});
            if (lt2.length()!=0)
            {
                lt2=lt2+" milles ";
            }
            chaine=lt1+" millions "+lt2+" "+lt3;
            System.out.println(chaine)  ;
        }
        if (t&lt;=6 & t&gt;3)
        {
            lt1=convertrois(new int[]{args[0],args[1],args[2]});
            lt2=convertrois(new int[]{args[3],args[4],args[5]});
            chaine=lt1+" milles "+lt2;
            System.out.println(chaine)  ;
        }
        if (t&lt;=3 & t&gt;=1)
        {
            lt1=convertrois(new int[]{args[0],args[1],args[2]});
            chaine=lt1;
            System.out.println(chaine)  ;
        }
        
    }//======================FIN  MAIN===========================FIN MAIN=======================
    
    //======================DEBUT FONCTION======================DEBUT FONCTION=====================
    private static  String convertrois (int[] param )
    {
        String nblettre="" ;
        int i=0 ;
        while (i&lt;3) //permet de parcourir les trois nbre selectionnés exple  soit 123
        {
            //declaration de nb qui prend une valeur du tablaeu param
            int nb ;
            nb=param[i] ;
            switch (i)
            {
                
                case 0 : {          //pour centaines  exple -&gt; 1
                    switch(nb)
                    {
                        case 0 : {nblettre=nblettre+"";} break ;
                        case 1 : {nblettre="cent ";} break ;
                        case 2 : {nblettre="deux cent ";} break ;
                        case 3 :  {nblettre="trois cent ";} break ;
                        case 4 : {nblettre="quatre cent ";} break;
                        case 5 : {nblettre="cinq cent ";} break ;
                        case 6 :  {nblettre="six cent ";}break ;
                        case 7 : {nblettre="sept cent ";} break ;
                        case 8 : {nblettre="huit cent ";} break ;
                        case 9 :  {nblettre="noeuf cent ";}break ;
                    } break;
                }
                case 1 : { //pour les dizaines exple -&gt; 2
                    switch(nb)
                    {
                        case 0 : {nblettre=nblettre+"";} break ;
                        // permet de gerer onze ,douze...
                        case 1 : {nblettre=nblettre+""+test(param[2]);
                            i=i+1;
                        } break ;
                        case 2 : {nblettre=nblettre+"vingt";} break ;
                        case 3 :  {nblettre=nblettre+"trente";} break ;
                        case 4 : {nblettre=nblettre+"quarante";} break ;
                        case 5 : {nblettre=nblettre+"cinquante";} break ;
                        case 6 :  {nblettre=nblettre+"soixante";} break ;
                        case 7 : {nblettre=nblettre+"soixante "+test(param[2]);
                            i=i+1;
                        } break ;
                        case 8 : {nblettre=nblettre+"quatre vingt";} break ;
                        case 9 :  {nblettre=nblettre+"quatre vingt"+test(param[2]);
                            i=i+1;
                        }break ;
                    } break ;
                }
                
                case 2 :  {   //pour les unités exple -&gt; 3
                    switch(nb)
                    {
                        case 0 : {nblettre=nblettre+"";} break;
                        case 1 : {
                            //test pour eviter davoir une incohérance :( un milles trois cent)
                            if (t==4)
                            {
                                if (bol==false)
                                {
                                    nblettre=nblettre+" ";
                                    bol=true ;
                                }
                                else
                                {
                                    nblettre=nblettre+" un";
                                }
                            }
                            else
                            {
                                nblettre=nblettre+" un";
                            }
                        } break;
                        case 2 : {nblettre=nblettre+" deux";} break;
                        case 3 :  {nblettre=nblettre+" trois";}break;
                        case 4 : {nblettre=nblettre+" quatre";} break;
                        case 5 : {nblettre=nblettre+" cinq";} break;
                        case 6 :  {nblettre=nblettre+" six";}break;
                        case 7 : {nblettre=nblettre+" sept";} break;
                        case 8 : {nblettre=nblettre+" huit";} break;
                        case 9 :  {nblettre=nblettre+" noeuf";}break;
                    }break;
                }
                default:
            }
            i=i+1;         //incrementation de i pour passer au 2 -&gt;dizaine
        }//fin while
        return nblettre ;
    }//fin fonction convertrois
    
    //=====================FIN FONCTION==========================FIN FONCTION===============
    //debut fonction test
    // permet de gerer onze ,douze...procedur d'apel test(param[2])
    private static String test( int snb  )
    {
        String lettre="" ;
        switch (snb) {
            case 0 : {lettre=" dix";} break;
            case 1 : {lettre=" onze";} break;
            case 2 : {lettre=" douze";} break;
            case 3 :  {lettre=" treize";}break;
            case 4 : {lettre=" quatorze";} break;
            case 5 : {lettre=" quinze";} break;
            case 6 :  {lettre=" seize";}break;
            case 7 : {lettre=" dix sept";} break;
            case 8 : {lettre=" dix huit";} break;
            case 9 :  {lettre=" dix noeuf";}break;
        }
        return lettre ;
    };//fin fonction test
    private static String lire()
    {
        String  lue=null ;
        try
        {
            lue= new java.io.BufferedReader(new java.io.InputStreamReader(System.in)).readLine() ;
        }
        catch(java.io.IOException e){}
        return lue;
    }
}//=========================== FIN ================================================
	
```