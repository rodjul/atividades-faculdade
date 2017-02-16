
<!DOCTYPE html>
<html>
	<head>
		<title><?php print $cabecalho_title; ?></title>
		<meta charset='utf-8' />
        <link rel="stylesheet" href="css/style.css" />
	</head>
	<body>
		<header>
            <figure>
                <img alt="logo" src="img/logo.jpg"  id="logo" />
            </figure>
			<form class="form1 fixpesq">
                <label for="pesquisa">Pesquisar:</label><input type="search" id="pesquisa" name="pesquisa" value="" placeholder="Pesquise aqui" />
                
                <!--<input type="submit" value="" class="iconepesquisa">-->
			</form>
            <section class="form2 fixmenu">
                 <?php
                    $usuario = mysqli_query($conexao,"SELECT nome,imagem FROM usuarios") or die("Não foi possível executar a SQL:".mysqli_error($conexao));
                    if($usuario){
                        while($row = mysqli_fetch_array($usuario)){
                            /*echo "<article>\n";
                            echo "\t\t<p class='usuario'>".$row['nome']."</p>\n";
                            echo "\t\t<img class='imgusuario' src='".$row['imagem']."'/>\n";
                            echo "<ul>
                                    <li><a href=''>Adionar noticias</a></li>
                                    <li>Perfil</>
                                    <li>Sair</li>
                            ";
                            echo "\t\t</article>\n";*/
                            $nome = $row['nome'];
                            $imagem = $row['imagem'];
                            $nome1 = "Rodrigo rodrigo roDrigo rodrigo 123";
                        }
                    }
                ?>
                <ul class="profile-wrapper">
                    <li>
                        <!-- user profile -->
                        <div class="profile">
                            <img src="<?php print $imagem ?>" />
                            <a href="#" class="name"><?php print $nome ?></a>

                            <!-- more menu -->
                            <ul class="menu">
                                <li><a href="crud-paginas.php">Adicionar notícias</a></li>
                                <li><a href="#">Perfil</a></li>
                                <li><a href="#">Log out</a></li>
                            </ul>
                        </div>
                    </li>
                </ul>
            </section>

		</header>
		<nav>
			<ul class="nav fixnav">
				<li class="vermelho"><a href="index.html">Home</a></li>
				<li class="amarelo"><a href="atualidades.php">Atualidades</a></li>
				<li class="laranja"><a href="economia.php">Economia</a></li>
				<li class="verde"><a href="esportes.php">Esportes</a></li>
				<li class="roxo"><a href="celebridades.php">Celebridades</a></li>
				<li class="azul"><a href="noticiasmundo.php">Notícias do mundo</a></li>
				<li class="vermelho"><a href="cadastrase.php">Cadastre-se</a></li>
			</ul>
		</nav>
        